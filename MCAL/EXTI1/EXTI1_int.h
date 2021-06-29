/******************************************/
/* Author      : Ahmed Khalid             */
/* Description : Interface file for EXTI1 */
/* Date        : 6 Sep 2019               */
/* Version     : 1.0V                     */
/******************************************/



#ifndef EXTI1_INT_H
#define EXTI1_INT_H


#define EXTI1_LOW_LEVEL      1
#define EXTI1_IOC            2
#define EXTI1_FALLING_EDGE   3
#define EXTI1_RISING_EDGE    4



/* Initialize EXTI1 */
void EXTI1_voidInit(void);

/* Enable EXTI1 */
void EXTI1_voidEnable(void);

/* Disable EXTI1 */
void EXTI1_voidDisable(void);


/* Changes Interrupt Sense Control of EXTI1 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI1_LOW_LEVEL                 */          
/*          EXTI1_IOC                       */
/*          EXTI1_FALLING_EDGE              */
/*          EXTI1_RISING_EDGE               */
/********************************************/   
/*         IOC: Interrupt On Change         */

void EXTI1_voidModeChange(u8 u8ModeCpy);


/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void EXTI1_voidSetCallBack(PF PfFuncAddrCpy);









#endif