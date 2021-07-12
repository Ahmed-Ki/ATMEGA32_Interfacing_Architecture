/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for ADC */
/* Date        : 7 Sep 2019           */
/* Version     : 1.0V                 */
/**************************************/


#ifndef ADC_PRIV_H
#define ADC_PRIV_H


#define AREF        4
#define AVCC        5
#define INTERNAL    3

#define LEFT_ADJUSTMENT         1
#define RIGHT_ADJUSTMENT        0


#define ADC0    DIO_PIN_0
#define ADC1    DIO_PIN_1
#define ADC2    DIO_PIN_2
#define ADC3    DIO_PIN_3
#define ADC4    DIO_PIN_4
#define ADC5    DIO_PIN_5
#define ADC6    DIO_PIN_6
#define ADC7    DIO_PIN_7


#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7


#define DIVIDE_BY_2     11       
#define DIVIDE_BY_4     12 
#define DIVIDE_BY_8     13
#define DIVIDE_BY_16    14
#define DIVIDE_BY_32    15
#define DIVIDE_BY_64    16
#define DIVIDE_BY_128   17






/* Memory mapped address of ADC Multiplexer Selection Register (ADMUX) */
#define ADMUX       *((volatile u8 *)  0x27)

/* Memory mapped address of ADC Control and Status Register (ADCSRA) */
#define ADCSRA      *((volatile u8 *)  0x26)

/* Memory mapped address of Special Function IO Register (SFIOR) */
#define SFIOR       *((volatile u8 *)  0x50)

/* Memory mapped address of ADC Data Register (ADCL) */
#define ADCL        *((volatile u8 *)  0x25)

/* Memory mapped address of ADC Data Register (ADCH) */
#define ADCH        *((volatile u8 *)  0x24)







#endif