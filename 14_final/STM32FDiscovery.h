typedef volatile struct{
     unsigned int rRCC_CR;
     unsigned int rRCC_PLLCFGR;
     unsigned int rRCC_CFGR;
     unsigned int rRCC_CIR;
     unsigned int rRCC_AHB1RSTR;
     unsigned int reserved1;
     unsigned int reserved2;
     unsigned int reserved3;
     unsigned int reserved4;
     unsigned int reserved5;
     unsigned int reserved6;
     unsigned int reserved7;
     unsigned int rRCC_AHB1ENR;
     unsigned int reserved8;
     unsigned int reserved9;
     unsigned int reserved10;
     unsigned int rRCC_APB1ENR;
     unsigned int rRCC_APB2ENR;
}tREG_RCC;

typedef volatile struct{
	unsigned int rMODER;
	unsigned int rOTYPER;
	unsigned int rOSPEEDR;
	unsigned int rPUPDR;
	unsigned int rIDR;
	unsigned int rODR;
	unsigned int reserved1;
	unsigned int reserved2;
	unsigned int rAFRL;
	unsigned int rAFRH;
}REG_GPIO;

typedef volatile struct{
	unsigned int rSR;
	unsigned int rDR;
	unsigned int rBRR;
	unsigned int rCR1;
	unsigned int rCR2;
	unsigned int rCR3;
	unsigned int reserved;
}REG_USART;

typedef volatile struct{
	unsigned int rCR1;
	unsigned int rCR2;
	unsigned int rSMCR;
	unsigned int rDIER;
	unsigned int rSR;
	unsigned int rEGR;
	unsigned int rCCMR1;
	unsigned int rCCMR2;
	unsigned int rCCER;
	unsigned int rCNT;
	unsigned int rPSC;
	unsigned int rARR;
	unsigned int reserved2;
	unsigned int rCCR1;
	unsigned int rCCR2;
	unsigned int rCCR3;
	unsigned int rCCR4;
	unsigned int reserved3;
	unsigned int rDCR;
	unsigned int rDMAR;
}TIM2to5;

typedef volatile struct{
	unsigned int rMEMRMP;
	unsigned int rPMC;
	unsigned int rEXTICR1;
	unsigned int rEXTICR2;
	unsigned int rEXTICR3;
	unsigned int rEXTICR4;
	unsigned int rCMPCR;
}REG_SYSCFG;

typedef volatile struct{
	unsigned int rIMR;
	unsigned int rEMR;
	unsigned int rRTSR;
	unsigned int rFTSR;
	unsigned int rSWIER;
	unsigned int rPR;
}REG_EXTI;

typedef volatile struct{
    unsigned int rSR;
    unsigned int rCR1;
    unsigned int rCR2;
    unsigned int rSMPR1;
    unsigned int rSMPR2;
    unsigned int rJOFR1;
    unsigned int rJOFR2;
    unsigned int rJOFR3;
    unsigned int rJOFR4;
    unsigned int rHTR;
    unsigned int rLTR;
    unsigned int rSQR1;
    unsigned int rSQR2;
    unsigned int rSQR3;
    unsigned int rJSQR;
    unsigned int rJDR1;
    unsigned int rJDR2;
    unsigned int rJDR3;
    unsigned int rJDR4;
    unsigned int rDR;
    unsigned int rCSR;
    unsigned int rCCR;
    unsigned int rCDR;
}REG_ADC;

typedef volatile struct{
	unsigned int rCTRL;
	unsigned int rLOAD;
	unsigned int rVAL;
	unsigned int rCALIB;
}REG_SYSTICK;



// RCC register //
#define RCC_BASE 0x40023800
#define RCC ((tREG_RCC*)RCC_BASE)

#define RCC_CR          (RCC->rRCC_CR)
#define RCC_PLLCFGR     (RCC->rRCC_PLLCFGR)
#define RCC_CFGR        (RCC->rRCC_CFGR)
#define RCC_CIR         (RCC->rRCC_CIR)
#define RCC_AHB1RSTR    (RCC->rRCC_AHB1RSTR)
#define RCC_AHB1ENR     (RCC->rRCC_AHB1ENR)
#define RCC_APB1ENR     (RCC->rRCC_APB1ENR)
#define RCC_APB2ENR     (RCC->rRCC_APB2ENR)

// SYSCFG register //
#define SYSCFG_BASE 0x40013800
#define SYSCFG ((REG_SYSCFG*)SYSCFG_BASE)

#define SYSCFG_MEMRMP   (SYSCFG->rMEMRMP)
#define SYSCFG_PMC      (SYSCFG->rPMC   )
#define SYSCFG_EXTICR1  (SYSCFG->rEXTICR1)
#define SYSCFG_EXTICR2  (SYSCFG->rEXTICR2)
#define SYSCFG_EXTICR3  (SYSCFG->rEXTICR3)
#define SYSCFG_EXTICR4  (SYSCFG->rEXTICR4)
#define SYSCFG_CMPCR    (SYSCFG->rCMPCR )

// SYSTICK register //
#define SYSTICK_BASE 0xE000E010
#define SYSTICK ((REG_SYSTICK*)SYSTICK_BASE)

#define SYSTICK_CTRL	(SYSTICK->rCTRL)
#define SYSTICK_LOAD	(SYSTICK->rLOAD)
#define SYSTICK_VAL		(SYSTICK->rVAL)
#define SYSTICK_CALIB	(SYSTICK->rCALIB)

// EXTI register //
#define EXTI_BASE 0x40013C00
#define EXTI ((REG_EXTI*)EXTI_BASE)

#define EXTI_IMR    (EXTI->rIMR)
#define EXTI_EMR    (EXTI->rEMR)
#define EXTI_RTSR   (EXTI->rRTSR)
#define EXTI_FTSR   (EXTI->rFTSR)
#define EXTI_SWIER  (EXTI->rSWIER)
#define EXTI_PR     (EXTI->rPR)

// GPIO A //
#define GPIOA_BASE 0x40020000
#define GPIOA ((REG_GPIO*)GPIOA_BASE)

#define GPIOA_MODER		(GPIOA->rMODER)
#define GPIOA_OTYPER  	(GPIOA->rOTYPER)
#define GPIOA_OSPEEDR 	(GPIOA->rOSPEEDR)
#define GPIOA_PUPDR  	(GPIOA->rPUPDR)
#define GPIOA_IDR    	(GPIOA->rIDR)
#define GPIOA_ODR		(GPIOA->rODR)
#define GPIOA_AFRL		(GPIOA->rAFRL)
#define GPIOA_AFRH		(GPIOA->rAFRH)

// GPIO C //
#define GPIOC_BASE 0x40020800
#define GPIOC ((REG_GPIO*)GPIOC_BASE)

#define GPIOC_MODER		(GPIOC->rMODER)
#define GPIOC_OTYPER  	(GPIOC->rOTYPER)
#define GPIOC_OSPEEDR 	(GPIOC->rOSPEEDR)
#define GPIOC_PUPDR  	(GPIOC->rPUPDR)
#define GPIOC_ODR		(GPIOC->rODR)
#define GPIOC_AFRL		(GPIOC->rAFRL)
#define GPIOC_AFRH		(GPIOC->rAFRH)

// GPIO D //
#define GPIOD_BASE 0x40020C00
#define GPIOD ((REG_GPIO*)GPIOD_BASE)

#define GPIOD_MODER		(GPIOD->rMODER)
#define GPIOD_OTYPER  	(GPIOD->rOTYPER)
#define GPIOD_OSPEEDR 	(GPIOD->rOSPEEDR)
#define GPIOD_PUPDR  	(GPIOD->rPUPDR)
#define GPIOD_ODR		(GPIOD->rODR)
#define GPIOD_AFRL		(GPIOD->rAFRL)
#define GPIOD_AFRH		(GPIOD->rAFRH)

// GPIO G //
#define GPIOG_BASE 0x40021800
#define GPIOG ((REG_GPIO*)GPIOG_BASE)

#define GPIOG_MODER		(GPIOG->rMODER) 
#define GPIOG_OTYPER  	(GPIOG->rOTYPER)
#define GPIOG_OSPEEDR 	(GPIOG->rOSPEEDR) 
#define GPIOG_PUPDR  	(GPIOG->rPUPDR)
#define GPIOG_ODR		(GPIOG->rODR) 
#define GPIOG_AFRL		(GPIOG->rAFRL) 
#define GPIOG_AFRH		(GPIOG->rAFRH)

// USART 2 //
#define USART2_BASE 0x40004400
#define USART2 ((REG_USART*)USART2_BASE)

#define USART2_SR		(USART2->rSR)
#define USART2_DR		(USART2->rDR)
#define USART2_BRR		(USART2->rBRR)
#define USART2_CR1		(USART2->rCR1)
#define USART2_CR2		(USART2->rCR2)
#define USART2_CR3		(USART2->rCR3)

// Timer 2 //
#define TIM2_BASE 0x40000000
#define TIM2 ((TIM2to5*)TIM2_BASE)

#define TIM2_CR1		(TIM2->rCR1)
#define TIM2_DIER		(TIM2->rDIER)
#define TIM2_SR			(TIM2->rSR)
#define TIM2_EGR		(TIM2->rEGR)
#define TIM2_CNT		(TIM2->rCNT)
#define TIM2_PSC		(TIM2->rPSC)
#define TIM2_ARR		(TIM2->rARR)

// Timer 3 //
#define TIM3_BASE 0x40000400
#define TIM3 ((TIM2to5*)TIM3_BASE)

#define TIM3_CR1		(TIM3->rCR1)
#define TIM3_CR2		(TIM3->rCR2)
#define TIM3_SMCR		(TIM3->rSMCR)
#define TIM3_DIER		(TIM3->rDIER)
#define TIM3_SR			(TIM3->rSR)
#define TIM3_EGR		(TIM3->rEGR)
#define TIM3_CCMR1		(TIM3->rCCMR1)
#define TIM3_CCMR2		(TIM3->rCCMR1)
#define TIM3_CCER		(TIM3->rCCER)
#define TIM3_CNT		(TIM3->rCNT)
#define TIM3_PSC		(TIM3->rPSC)
#define TIM3_ARR		(TIM3->rARR)
#define TIM3_CCR1		(TIM3->rCCR1)
#define TIM3_CCR2		(TIM3->rCCR2)
#define TIM3_CCR3		(TIM3->rCCR3)
#define TIM3_CCR4		(TIM3->rCCR4)
#define TIM3_DCR		(TIM3->rDCR)
#define TIM3_DMAR		(TIM3->rDMAR)

// ADC1
#define ADC1_BASE 0x40012000
#define ADC1 ((REG_ADC*)ADC1_BASE)

#define ADC1_SR      (ADC1->rSR)
#define ADC1_CR1     (ADC1->rCR1)
#define ADC1_CR2     (ADC1->rCR2)
#define ADC1_SMPR1   (ADC1->rSMPR1)
#define ADC1_SMPR2   (ADC1->rSMPR2)
#define ADC1_JOFR1   (ADC1->rJOFR1)
#define ADC1_JOFR2   (ADC1->rJOFR2)
#define ADC1_JOFR3   (ADC1->rJOFR3)
#define ADC1_JOFR4   (ADC1->rJOFR4)
#define ADC1_HTR     (ADC1->rHTR)
#define ADC1_LTR     (ADC1->rLTR)
#define ADC1_SQR1    (ADC1->rSQR1)
#define ADC1_SQR2    (ADC1->rSQR2)
#define ADC1_SQR3    (ADC1->rSQR3)
#define ADC1_JSQR    (ADC1->rJSQR)
#define ADC1_JDR1    (ADC1->rJDR1)
#define ADC1_JDR2    (ADC1->rJDR2)
#define ADC1_JDR3    (ADC1->rJDR3)
#define ADC1_JDR4    (ADC1->rJDR4)
#define ADC1_DR      (ADC1->rDR)
#define ADC1_CSR     (ADC1->rCSR)
#define ADC1_CCR     (ADC1->rCCR)
#define ADC1_CDR     (ADC1->rCDR)


#define FLASH_ACR *(volatile unsigned *)0x40023C00
#define NVIC_ISER0 *(volatile unsigned *)0xE000E100
#define NVIC_ISER1 *(volatile unsigned *)0xE000E104

#ifndef INC_REGS_H_
#define INC_REGS_H_


/* Flash interface */
#define	LATENCY_BIT_IDX		0

/* Clock register */
// RCC_CR
#define	HSEON_BIT_IDX		16
#define	HSERDY_BIT_IDX		17
#define	PLLON_BIT_IDX		24
#define	PLLRDY_BIT_IDX		25
// RCC_PLLCFGR
#define PLLM_BIT_IDX		0
#define	PLLN_BIT_IDX		6
#define	PLLP_BIT_IDX		16
#define PLLSRC_BIT_IDX		22
#define	PLLQ_BIT_IDX		24
// RCC_CFGR
#define	SW_BIT_IDX			0
#define	SWS_BIT_IDX			2
#define	PPRE1_BIT_IDX		10
#define	PPRE2_BIT_IDX		13
#define MCO1_BIT_IDX		21
#define	MCO1PRE_BIT_IDX		24
// RCC_APB1ENR
#define	TIM2EN_BIT_IDX		0
#define TIM3EN_BIT_IDX		1
#define USART2EN_BIT_IDX	17
// RCC_AHB1ENR
#define GPIOAEN_BIT_IDX		0
#define GPIOCEN_BIT_IDX		2
// RCC_APB2ENR
#define ADC1EN_BIT_IDX		8

/* Timer register */
// TIMx_DIER
#define	UIE_BIT_IDX			0
// TIMx_EGR
#define	UG_BIT_IDX			0
// TIMx_CR1
#define CEN_BIT_IDX			0
#define UDIS_BIT_IDX		1
#define URS_BIT_IDX			2
#define OPM_BIT_IDX			3
#define DIR_BIT_IDX			4
#define CMS_BIT_IDX			5
#define ARPE_BIT_IDX		7
#define CKD_BIT_IDX			8
// TIMx_CR2
#define MMS_BIT_IDX			4
// TIMx_SMCR
#define SMS_BIT_IDX			0
#define MSM_BIT_IDX			7
// TIMx_CCMR1
#define OC1FE_BIT_IDX		2
#define OC1PE_BIT_IDX 		3
#define OCM1_BIT_IDX		4


#define ENA_BIT_IDX			0
#define	END_BIT_IDX			3

#define EXTI0_BIT_IDX		0

#define MR0_BIT_IDX			0

#define TR0_BIT_IDX			0

#define RS6_BIT_IDX			6

#define PR0_BIT_IDX			0

/* GPIO register */
// GPIO_MODER
#define MODER0_BIT_IDX		0
#define MODER1_BIT_IDX		2
#define MODER2_BIT_IDX		4
#define MODER3_BIT_IDX		6
#define MODER6_BIT_IDX		12
#define MODER12_BIT_IDX		24
#define MODER13_BIT_IDX		26
#define MODER14_BIT_IDX		28
#define MODER15_BIT_IDX		30

// GPIO_AFRL
#define AFRL0_BIT_IDX		0
#define AFRL1_BIT_IDX		4
#define AFRL2_BIT_IDX		8
#define AFRL3_BIT_IDX		12
#define AFRL6_BIT_IDX		24

/* Interrupt */
#define	TIM2_INT_IDX		28
#define TIM3_INT_IDX		29
#define USART2_INT_IDX		6

/* USART */
// USART_CR1
#define RE_BIT_IDX			2
#define TE_BIT_IDX			3
#define RXNEIE_BIT_IDX		5
#define M_BIT_IDX			12
#define UE_BIT_IDX			13

// USART_CR2
#define STOP_BIT_IDX		12

// USART_BRR
#define DIVM_BIT_IDX		4
#define DIVF_BIT_IDX		0

// USART_SR
#define RXNE_BIT_IDX		5
#define TC_BIT_IDX			6
#define TXE_BIT_IDX			7

/* ADC regs */
// ADC_SQR1
#define L_BIT_IDX			20
// ADC_SQR3
#define SQ1_BIT_IDX			0
// ADC_CR2
#define ADON_BIT_IDX		0
#define CONT_BIT_IDX		1
#define SWSTART_BIT_IDX		30
// ADC_SR
#define EOC_BIT_IDX			1

#endif /* INC_REGS_H_ */
