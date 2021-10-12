/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Interface file for TIMER1 */
/* Date        : 1 Oct 2021                */
/* Version     : 1.0V                      */
/*******************************************/


#ifndef TIMER1_INT_H
#define TIMER1_INT_H

/*  Initialization function for TIMER1    */
/*  Sets operation Mode and Prescaler     */
/*  of TIMER1 according to choices in cfg */
void TIMER1_voidInit(void);

/* Enable Overflow Interrupt */
void TIMER1_voidInterruptOVEnable(void);

/* Disable Overflow Interrupt */
void TIMER1_voidInterruptOVDisable(void);



/* Enable CTC Interrupt */
void TIMER1_voidInterruptCTCEnable(void);

/* Disable CTC Interrupt */
void TIMER1_voidInterruptCTCDisable(void);



#endif