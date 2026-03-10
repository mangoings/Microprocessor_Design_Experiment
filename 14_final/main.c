#include "STM32FDiscovery.h"
#include "regs.h"

// 변수 선언
int duty = 0;
int duty_max = 1024;
int state = 0; // 0: OFF, 1: ON

// PWM(펄스폭 변조) 모터제어 초기화
void init_PWM(void) {
    /* TIM3 설정 */
    RCC_APB1ENR |= (0x1 << TIM3EN_BIT_IDX); // TIM3 타이머 클럭 활성화
    NVIC_ISER0  |= 0x1 << TIM3_INT_IDX; // TIM3의 인터럽트 컨트롤러(NVIC) 활성화

    TIM3_PSC  = 840 - 1; // 타이머 클럭 주기 설정
    TIM3_ARR  = 1000 - 1; //  PWM 주기 설정 (840 * 1000)
	// 주기를 설정 안해주면 자동으로 0의 값을 가지는데 이러면 매 클럭 사이클마다 오버플로우할 수 있어 PWM제어가 원할하지 않을 수 있음
    
	TIM3_CR1 &= ~(0x3 << CMS_BIT_IDX); // 엣지 얼라인 모드
    TIM3_CR1 &= ~(0x1 << DIR_BIT_IDX); // 업카운터
    TIM3_CR1 &= ~(0x3 << CKD_BIT_IDX); // 클럭 분할 비활성화 (활성화하면 클럭 주기가 길어져 PWM제어에 불리)
    TIM3_CR1 &= ~(0x1 << ARPE_BIT_IDX); // ARR 레지스터 버퍼링 비활성화 (ARR 레지스터가 즉시 업데이트되도록 설정)
	// PWM 신호 생성을 타이머가 주기마다 0에서 설정된 값(ARR)까지 증가하고 다시 0으로 리셋되는 방식인 엣지 얼라인 모드로 설정 
	// 쉽고 일반적

    TIM3_SMCR &= ~(0x7 << SMS_BIT_IDX); // 타이머를 내부 클럭으로 설정 (외부 트리거 없이 내부 클럭으로 동작)
    TIM3_SMCR &= ~(0x1 << MSM_BIT_IDX); // 마스터/슬레이브 모드 비활성화 (타이머가 독립적으로 동작)
	// 타이머가 자체 클럭으로 동작 -> PWM신호 지속적으로 생성

    TIM3_CCMR1 |= (0x1 << OC1PE_BIT_IDX); // 출력 비교 프리로드 활성화 (다음 PWM 주기에서 비교 값을 업데이트)
    TIM3_CCMR1 |= (0x6 << OCM1_BIT_IDX); // PWM 모드 1 설정
    TIM3_CCMR1 &= ~(0x1 << OC1FE_BIT_IDX); // 빠른 모드를 비활성화(PWM 출력을 안정적으로 유지)

    TIM3_CCER = 0; // TIM3의 초기 설정 = 채널 출력 비활성화
    TIM3_CCR1 = 0; // TIM3의 초기 설정 = 채널 1의 비교값을 0, PWM 출력 비활성화

    TIM3_CR2 &= ~(0x7 << MMS_BIT_IDX); // 트리거 출력 리셋
	// 버튼을 누르기 전까지는 동작을 안시키기 위해서 (LED, Motor)
}

// 시스템 클럭 설정
void clk(void) {
    RCC_CR = 0;
    RCC_PLLCFGR = 0;
    RCC_CFGR = 0;
	// 모든 클럭 제어 레지스터 리셋

    RCC_CR |= (1<<16); // 외부 고속 클럭(HSE) 활성화
    while((RCC_CR & (1<<17)) == 0); // HSE가 안정화될 때까지 기다림 
	// 정밀하고 안정된 클럭 신호

    RCC_PLLCFGR |= 8; 
    RCC_PLLCFGR |= (336<<6); 
    RCC_PLLCFGR |= (0<<16); 
    RCC_PLLCFGR |= (7<<24);
	// PLL (Phase Locked Loop): 클럭 신호 증폭/감소 -> 필요한 주파수 생성

    RCC_PLLCFGR |= (1<<22); // PLL 소스를 HSE로 설정

    RCC_CR |= (1<<24); // PLL 활성화
    while((RCC_CR & (1<<25)) == 0); // PLL이 안정화될 때까지 기다림 

    FLASH_ACR |= 5; // 플래시 메모리의 읽기 시간 조정
    RCC_CFGR |= 2; // PLL을 시스템 클럭으로 설정 (높은 주파수에서 동작 가능)
    while((RCC_CFGR & (12)) != 8); //  PLL이 설정될 때까지 기다림 

    RCC_CFGR |= (1<<12) | (1<<10);
    RCC_CFGR |= (1<<15);
	// APB1/APB2: 주변 장치 버스, 주변 장치가 안정적으로 동작할 수 있게
}

// PWM제어 시작
void start_PWM(void) {
    TIM3_CCER |= 0x1; // TIM3 채널 1 출력 활성화
    TIM3_CR1 |= 0x1; // TIM3 카운터 활성화 
}

// LED, 모터 토글
void EXTI0_IRQHandler() {
    if(EXTI_PR & (1 << 0)) { // 버튼을 눌렀는데
        if(state == 0) { // OFF상태라면
            // LED와 모터 켜기
            GPIOG_ODR |= 1<<13; //LED 켜기 (PG13 핀)
            TIM3_CCR1 = duty_max; // 모터 켜기 (최대 duty)
            state = 1; // ON 상태
        } else { // ON상태라면
            // LED와 모터 끄기
            GPIOG_ODR &= ~(1<<13); //LED 끄기 (PG13 핀)
            TIM3_CCR1 = 0; // 모터 끄기 (duty = 0)
            state = 0; // OFF상태
        }
        EXTI_PR |= 1<<0; // EXTI0 대기 비트 클리어
		// 버튼 누르는 동작(인터럽트)을 다시 받아야 하니까
    }
}

int main(void) {
    clk(); // 함수호출

    RCC_CFGR |= 0x04600000; //시스템 클럭 레지스터 설정

    /* PORT A */
    RCC_AHB1ENR  |= 1<<0; // PORT A 클럭 활성화
    GPIOA_MODER  |= 0<<0; // 입력 모드 설정 (버튼 입력 받음)
    GPIOA_OTYPER |= 0<<0; // 출력 타입 푸시-풀로 설정
    GPIOA_PUPDR  |= 0<<0; // 풀업/풀다운 저항 사용x

    /* button intr set (버튼 활성화) */
    SYSCFG_EXTICR1  |= 0<<0; // EXTI0을 PA0에 연결
    EXTI_IMR        |= 1<<0; // EXTI0 인터럽트 활성화
    EXTI_RTSR       |= 1<<0; // 상승 엣지 트리거 활성화 (버튼이 눌리면 인터럽트 발생)
    EXTI_FTSR       |= 0<<0; // 하강 엣지 트리거 비활성화 (버튼을 뗄때 인터럽트 발생x)
    NVIC_ISER0      |= 1<<6; // 인터럽트 컨트롤러(NVIC)에서 EXTI0 인터럽트 활성화 (NVIC에서 인터럽트 신호 처리)

    /* PORT G */
    RCC_AHB1ENR  |= 1<<6; // PORT G 클럭 활성화
    GPIOG_MODER  |= 1<<26; // PG13 핀을 출력 모드로 설정 (LED 출력)
    GPIOG_OTYPER |= 0x00000000; // 출력 타입 푸시-풀로 설정
    GPIOG_PUPDR  |= 0x00000000; // 풀업/풀다운 저항 사용x

    /* PORT C */
    RCC_AHB1ENR |= 1<<GPIOCEN_BIT_IDX; // PORT C 클럭 활성화
    GPIOC_MODER &= ~(0x3 << MODER6_BIT_IDX); // PC6 모드 클리어 (PC6 핀 사용을 위해)
    GPIOC_MODER |= 0x2 << MODER6_BIT_IDX; // PC6을 대체 기능 모드로 설정 (PWM 출력을 위해)
    GPIOC_AFRL |= 0x2 << AFRL6_BIT_IDX; // PC6 핀의 대체 기능을 설정 (motor 출력)

    init_PWM(); // 함수호출
    start_PWM(); // 함수호출
    
    while(1) {
        // 메인 루프 (무한 루프로 프로그램이 종료되지x)
    }
}
