/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for ADC */
/* Date        : 7 Sep 2019           */
/* Version     : 1.0V                 */
/**************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"


PF ADC_PfCallBackAddr = NULL ;

void ADC_voidInit(void)
{
	#if ADC_VOLTAGE_REFERENCE == AVCC
      SET_BIT(ADMUX , 6 );
      CLEAR_BIT(ADMUX , 7);

	#elif ADC_VOLTAGE_REFERENCE == AREF
	  CLEAR_BIT(ADMUX , 6);
	  CLEAR_BIT(ADMUX , 7);
	
	#elif ADC_VOLTAGE_REFERENCE == INTERNAL
	  SET_BIT(ADMUX , 6 );
	  SET_BIT(ADMUX , 7 );
	
	/* Default voltage reference is AVCC */
	#else 	
	  SET_BIT(ADMUX , 6 );
      CLEAR_BIT(ADMUX , 7);
	#endif 
	
	
	#if ADC_CHANNEL_NUMBER == ADC0
	  CLEAR_BIT(ADMUX , 0 );
	  CLEAR_BIT(ADMUX , 1 );
	  CLEAR_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == ADC1
	  SET_BIT(ADMUX , 0 );
	  CLEAR_BIT(ADMUX , 1 );
	  CLEAR_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == ADC2
	  CLEAR_BIT(ADMUX , 0 );
	  SET_BIT(ADMUX , 1 );
	  CLEAR_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );

	
	#elif ADC_CHANNEL_NUMBER == ADC3
	   SET_BIT(ADMUX , 0 );
	  SET_BIT(ADMUX , 1 );
	  CLEAR_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	#elif ADC_CHANNEL_NUMBER == ADC4
	 CLEAR_BIT(ADMUX , 0 );
	  CLEAR_BIT(ADMUX , 1 );
	  SET_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == ADC5
	  SET_BIT(ADMUX , 0 );
	  CLEAR_BIT(ADMUX , 1 );
	  SET_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == ADC6
	
	  CLEAR_BIT(ADMUX , 0 );
	  SET_BIT(ADMUX , 1 );
	  SET_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == ADC7
	  SET_BIT(ADMUX , 0 );
	  SET_BIT(ADMUX , 1 );
	  SET_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );

	/* Default channel is ADC0 */  
	#else
	  CLEAR_BIT(ADMUX , 0 );
	  CLEAR_BIT(ADMUX , 1 );
	  CLEAR_BIT(ADMUX , 2 );
	  CLEAR_BIT(ADMUX , 3 );
	  CLEAR_BIT(ADMUX , 4 );
	  
	#endif
	
	/* Disable ADC */
	CLEAR_BIT(ADCSRA , 7 );
	/* Stop conversion */
	CLEAR_BIT(ADCSRA , 6 );
	/* Disable auto trigger */
	CLEAR_BIT(ADCSRA , 5 );
	/* Clear ADC interrupt flag */ 
	SET_BIT(ADCSRA , 4 );
	/* Disable interrupt */ 
	CLEAR_BIT(ADCSRA , 3 );
	
	#if ADC_RESULT_ADJUSTMENT == LEFT_ADJUSTMENT
	  SET_BIT(ADMUX , 5);
	
	#elif ADC_RESULT_ADJUSTMENT == RIGHT_ADJUSTMENT
	 CLEAR_BIT(ADMUX , 5);
	
    /* Default adjustment is RIGHT_ADJUSTMENT */
	#else
	 CLEAR_BIT(ADMUX , 5);
	#endif
	
	#if ADC_PRESCALER  ==   DIVIDE_BY_2
	 SET_BIT(ADCSRA, 0);
	 CLEAR_BIT(ADCSRA, 1);
	 CLEAR_BIT(ADCSRA, 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_4
	 CLEAR_BIT(ADCSRA, 0);
	 SET_BIT(ADCSRA, 1);
	 CLEAR_BIT(ADCSRA, 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_8
	 SET_BIT(ADCSRA, 0);
	 SET_BIT(ADCSRA, 1);
	 CLEAR_BIT(ADCSRA, 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_16
	 CLEAR_BIT(ADCSRA , 0);
	 CLEAR_BIT(ADCSRA , 1);
	 SET_BIT(ADCSRA , 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_32
	 SET_BIT(ADCSRA , 0);
	 CLEAR_BIT(ADCSRA , 1);
	 SET_BIT(ADCSRA , 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_64
	 CLEAR_BIT(ADCSRA , 0);
	 SET_BIT(ADCSRA , 1);
	 SET_BIT(ADCSRA , 2);
	#elif ADC_PRESCALER  == DIVIDE_BY_128
	 SET_BIT(ADCSRA , 0);
	 SET_BIT(ADCSRA , 1);
	 SET_BIT(ADCSRA , 2);

	/* Default in datasheet is DIVIDE_BY_2 but ADC works with max 200KHz */
	/* My ATMEGA32 frequency is set to 8MHz so i chose default			 */ 
	/* DIVIDE_BY_64 to get close to ADC sampling rate 		 		     */
	#else
     CLEAR_BIT(ADCSRA, 0);
	 SET_BIT(ADCSRA, 1);
	 SET_BIT(ADCSRA, 2);
	#endif
	
	#if ADC_AUTO_TRIGGER_SOURCE  == FREE_RUNNING_MODE
	 CLEAR_BIT(SFIOR, 5);
	 CLEAR_BIT(SFIOR, 6);
	 CLEAR_BIT(SFIOR, 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == ANALOG_COMPARATOR
	 SET_BIT(SFIOR, 5);
	 CLEAR_BIT(SFIOR, 6);
	 CLEAR_BIT(SFIOR, 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == EXTERNAL_INTERRPUT_REQUEST_0
	 CLEAR_BIT(SFIOR, 5);
	 SET_BIT(SFIOR, 6);
	 CLEAR_BIT(SFIOR, 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == TIMER_COUNTER_0_COMPARE_MATCH
	 SET_BIT(SFIOR , 5);
	 SET_BIT(SFIOR , 6);
	 CLEAR_BIT(SFIOR , 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == TIMER_COUNTER_0_OVERFLOW
	 CLEAR_BIT(SFIOR , 5);
	 CLEAR_BIT(SFIOR , 6);
	 SET_BIT(SFIOR , 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == TIMER_COUNTER_COMPARE_MATCH_B
	 SET_BIT(SFIOR , 5);
	 CLEAR_BIT(SFIOR , 6);
	 SET_BIT(SFIOR , 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == TIMER_COUNTER_1_OVERFLOW
	 CLEAR_BIT(SFIOR , 5);
	 SET_BIT(SFIOR , 6);
	 SET_BIT(SFIOR , 7);
	#elif ADC_AUTO_TRIGGER_SOURCE  == TIMER_COUNTER_1_CAPTURE_EVENT
	 SET_BIT(SFIOR , 5);
	 SET_BIT(SFIOR , 6);
	 SET_BIT(SFIOR , 7);

	/* Default is FREE_RUNNING_MODE */
	#else
     CLEAR_BIT(SFIOR, 5);
	 CLEAR_BIT(SFIOR, 6);
	 CLEAR_BIT(SFIOR, 7);
	#endif
	
}

/* Enable ADC peripheral */
void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA , 7 );
}

/* Disable ADC peripheral */
void ADC_voidDisable(void)
{
	CLEAR_BIT(ADCSRA , 7 );
}

/* Enable ADC interrupt */
void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA , 3 );
}

/* Disable ADC interrupt */
void ADC_voidInterruptDisable(void)
{
	CLEAR_BIT(ADCSRA , 3 );
}

/* Signals ADC to start conversion */
void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA , 6 );
}

/* Set auto trigger source for ADC */
void ADC_voidSetAutoTrigger(void)
{
	SET_BIT(ADCSRA,5);
}

/* Clear auto trigger source for ADC */
void ADC_voidClearAutoTrigger(void)
{
	CLEAR_BIT(ADCSRA,5);
}

u16 ADC_u16ReadValue(void)
{
	u16 u16ReadValueLoc = 0;
	/* Start Conversion */
	SET_BIT(ADCSRA , 6 ); 

	/* Implementing interrupt in software */
	/* WAIT FOR INTERRUPT FLAG */
	while(GET_BIT(ADCSRA,4) == 0); 	
	/* Clear Interrupt flag */
	SET_BIT(ADCSRA , 4); 
	
	#if ADC_RESULT_ADJUSTMENT == LEFT_ADJUSTMENT
	u16ReadValueLoc = ADCH;
	#else
	u16ReadValueLoc = ADCL;
	u16ReadValueLoc |= (ADCH <<8);
	#endif
	return u16ReadValueLoc;
	
}


/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void ADC_voidSetCallBack(PF PfFuncAddrCpy)
{
	ADC_PfCallBackAddr = PfFuncAddrCpy;
}

void __vector__16 (void) __attribute__((signal    ,   used));
void __vector__16 (void)
{
    if (ADC_PfCallBackAddr != NULL)
    {
        ADC_PfCallBackAddr();  
    }

}


