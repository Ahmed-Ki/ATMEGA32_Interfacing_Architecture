/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Private file for TIMER2 */
/* Date        : 3 Oct 2021              */
/* Version     : 1.0V                    */
/*****************************************/


#ifndef TIMER2_PRIV_H
#define TIMER2_PRIV_H

#define NORMAL              0
#define PWM_PHASE_CORRECT   2
#define CTC                 4
#define FAST_PWM            6

#define NORMAL_OP               8 
#define TOGGLE_OC2_ON_COM       10   
#define CLEAR_OC2_ON_COM        12  
#define SET_OC2_ON_COM          14

#define CLEAR_OC2_ON_COM_SET_TOP    16
#define SET_OC2_ON_COM_CLEAR_TOP    18

#define CLEAR_OC2_ON_COM_UP_COUNTING    20
#define SET_OC2_ON_COM_UP_COUNTING      22

#define TIMER2_NO_CLOCK                         24
#define TIMER2_DIV_BY_1                         26 
#define TIMER2_DIV_BY_8                         28
#define TIMER2_DIV_BY_32                        80 
#define TIMER2_DIV_BY_64                        30
#define TIMER2_DIV_BY_128                       60 
#define TIMER2_DIV_BY_256                       32 
#define TIMER2_DIV_BY_1024                      34   

/* Memory mapped address of Timer/Counter Control Register (TCCR2) */
#define TCCR2    *((volatile u8 *)   0x45)

/* Memory mapped address of Timer/Counter Register (TCNT2) */
#define TCNT2    *((volatile u8 *)   0x44)

/* Memory mapped address of Output Compare Register (OCR2) */
#define OCR2     *((volatile u8 *)   0x43)

/* Memory mapped address of Timer/Counter Interrupt Mask Register (TIMSK) */
#define TIMSK    *((volatile u8 *)   0x59)

/* Memory mapped address of Timer/Counter Interrupt Flag Register (TIFR) */
#define TIFR     *((volatile u8 *)   0x58)





#endif