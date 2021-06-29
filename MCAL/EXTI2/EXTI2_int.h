/******************************************/
/* Author      : Ahmed Khalid             */
/* Description : Interface file for EXTI2 */
/* Date        : 6 Sep 2019               */
/* Version     : 1.0V                     */
/******************************************/



#ifndef EXTI2_INT_H
#define EXTI2_INT_H


#define EXTI2_FALLING_EDGE   3
#define EXTI2_RISING_EDGE    4



/* Initialize EXTI2 */
void EXTI2_voidInit(void);

/* Enable EXTI2 */
void EXTI2_voidEnable(void);

/* Disable EXTI2 */
void EXTI2_voidDisable(void);


/* Changes Interrupt Sense Control of EXTI2 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI2_FALLING_EDGE              */
/*          EXTI2_RISING_EDGE               */


void EXTI2_voidModeChange(u8 u8ModeCpy);


/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void EXTI2_voidSetCallBack(PF PfFuncAddrCpy);









#endif