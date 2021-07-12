/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for ADC */
/* Date        : 7 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/


#ifndef ADC_INT_H
#define ADC_INT_H

/* ADC initialization function */
void ADC_voidInit(void);

/* Enable ADC peripheral */
void ADC_voidEnable(void);

/* Disable ADC peripheral */
void ADC_voidDisable(void);

/* Enable ADC interrupt */
void ADC_voidInterruptEnable(void);

/* Disable ADC interrupt */
void ADC_voidInterruptDisable(void);

/* Signals ADC to start conversion */
void ADC_voidStartConversion(void);

/* Choose auto trigger source for ADC */
void ADC_voidAutoTrigger(u8 u8TriggerSource);

/* Read ADC value */
u16 ADC_u16ReadValue(void);

/* This is a CallBack function used in the Application layer */
/* to write your ISR (Interrupt Service Routine)             */
void ADC_voidSetCallBack(PF PfFuncAddrCpy);



#endif