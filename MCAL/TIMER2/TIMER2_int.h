/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Interface file for TIMER2 */
/* Date        : 3 Oct 2021                */
/* Version     : 1.0V                      */
/*******************************************/

#ifndef TIMER2_INT_H
#define TIMER2_INT_H

/*  Initialization function for TIMER2    */
/*  Sets operation Mode and Prescaler     */
/*  of TIMER2 according to choices in cfg */
void TIMER2_voidInit(void);

/* Enable Overflow Interrupt */
void TIMER2_voidInterruptOVEnable(void);

/* Disable Overflow Interrupt */
void TIMER2_voidInterruptOVDisable(void);

/* Enable CTC Interrupt */
void TIMER2_voidInterruptCTCEnable(void);

/* Disable CTC Interrupt */
void TIMER2_voidInterruptCTCDisable(void);

/* Reads the value of Timer/Counter register (TCNT2)      */
/* or the value of Output compare register (OC2) register */
/* depending on the mode configured in cfg                */
u8 TIMER2_voidReadTimerValue(void);

/* Sets value of Timer/Counter (TCNT2) register */
void TIMER2_voidSetTimerValue(u8 u8ValueCpy);

/* Sets value of Output Compare (OCR2) register */
void TIMER2_voidSetCompareValue(u8 u8ValueCpy);

/* This is a CallBack function used in the Application layer        */
/* to write your ISR (Interrupt Service Routine) for Timer Overflow */
void TIMER2_voidOVCallBack(PF PfFuncAddrCpy);

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for Timer CTC */
void TIMER2_voidCTCCallBack(PF PfFuncAddrCpy);

#endif