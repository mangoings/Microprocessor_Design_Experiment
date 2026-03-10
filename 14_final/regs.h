/*
 * regs.h
 *
 *  Created on: 2023. 4. 27.
 *      Author: User
 */

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
