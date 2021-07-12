/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Interface file for TIMER0 */
/* Date        : 15 Sep 2019               */
/* Version     : 1.0V                      */
/*******************************************/

#ifndef TIMER0_INT_H
#define TIMER0_INT_H

/*  Initialization function for TIMER0    */
/*  Sets operation Mode and Prescaler     */
/*  of TIMER0 according to choices in cfg */
void TIMER0_voidInit(void);

/* Enable Overflow Interrupt */
void TIMER0_voidInterruptOVEnable(void);

/* Disable Overflow Interrupt */
void TIMER0_voidInterruptOVDisable(void);

/* Enable CTC Interrupt */
void TIMER0_voidInterruptCTCEnable(void);

/* Disable CTC Interrupt */
void TIMER0_voidInterruptCTCDisable(void);

/* Reads the value of Timer/Counter register (TCNT0)      */
/* or the value of Output compare register (OC0) register */
/* depending on the mode configured in cfg                */
u8 TIMER0_voidReadTimerValue(void);

/* Sets value of Timer/Counter (TCNT0) register */
void TIMER0_voidSetTimerValue(u8 u8ValueCpy);

/* Sets value of Output Compare (OCR0) register */
void TIMER0_voidSetCompareValue(u8 u8ValueCpy);


/* This is a CallBack function used in the Application layer        */
/* to write your ISR (Interrupt Service Routine) for Timer Overflow */
void TIMER0_voidOVCallBack(PF PfFuncAddrCpy);

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for Timer CTC */
void TIMER0_voidCTCCallBack(PF PfFuncAddrCpy);

#endif