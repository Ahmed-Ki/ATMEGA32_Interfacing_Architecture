/******************************************/
/* Author      : Ahmed Khalid             */
/* Description : Interface file for EXTI0 */
/* Date        : 6 Sep 2019               */
/* Version     : 1.0V                     */
/******************************************/



#ifndef EXTI0_INT_H
#define EXTI0_INT_H


#define EXTI0_LOW_LEVEL      1
#define EXTI0_IOC            2
#define EXTI0_FALLING_EDGE   3
#define EXTI0_RISING_EDGE    4



/* Initialize EXTI0 */
void EXTI0_voidInit(void);

/* Enable EXTI0 */
void EXTI0_voidEnable(void);

/* Disable EXTI0 */
void EXTI0_voidDisable(void);


/* Changes Interrupt Sense Control of EXTI0 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI0_LOW_LEVEL                 */          
/*          EXTI0_IOC                       */
/*          EXTI0_FALLING_EDGE              */
/*          EXTI0_RISING_EDGE               */
/********************************************/   
/*         IOC: Interrupt On Change         */

void EXTI0_voidModeChange(u8 u8ModeCpy);


/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void EXTI0_voidSetCallBack(PF PfFuncAddrCpy);









#endif