/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Private file for TIMER0 */
/* Date        : 15 Sep 2019             */
/* Version     : 1.0V                    */
/*****************************************/


#ifndef TIMER0_PRIV_H
#define TIMER0_PRIV_H

#define NORMAL              0
#define PWM_PHASE_CORRECT   2
#define CTC                 4
#define FAST_PWM            6

#define NORMAL_OP               8 
#define TOGGLE_OC0_ON_COM       10   
#define CLEAR_OC0_ON_COM        12  
#define SET_OC0_ON_COM          14

#define CLEAR_OC0_ON_COM_SET_TOP    16
#define SET_OC0_ON_COM_CLEAR_TOP    18

#define CLEAR_OC0_ON_COM_UP_COUNTING    20
#define SET_OC0_ON_COM_UP_COUNTING      22

#define TIMER0_NO_CLOCK                         24
#define TIMER0_DIV_BY_1                         26 
#define TIMER0_DIV_BY_8                         28 
#define TIMER0_DIV_BY_64                        30 
#define TIMER0_DIV_BY_256                       32 
#define TIMER0_DIV_BY_1024                      34 
#define TIMER0_EXTERNAL_CLOCK_FALLING_EDGE      36 
#define TIMER0_EXTERNAL_CLOCK_RISING_EDGE       37 

/* Memory mapped address of Timer/Counter Control Register (TCCR0) */
#define TCCR0    *((volatile u8 *)   0x53)

/* Memory mapped address of Timer/Counter Register (TCNT0) */
#define TCNT0    *((volatile u8 *)   0x52)

/* Memory mapped address of Output Compare Register (OCR0) */
#define OCR0     *((volatile u8 *)   0x5C)

/* Memory mapped address of Timer/Counter Interrupt Mask Register (TIMSK) */
#define TIMSK    *((volatile u8 *)   0x59)

/* Memory mapped address of Timer/Counter Interrupt Flag Register (TIFR) */
#define TIFR     *((volatile u8 *)   0x58)





#endif