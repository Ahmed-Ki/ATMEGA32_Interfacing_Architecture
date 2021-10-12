/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Private file for TIMER1 */
/* Date        : 1 Oct 2021              */
/* Version     : 1.0V                    */
/*****************************************/


#ifndef TIMER1_PRIV_H
#define TIMER1_PRIV_H






/* Memory mapped address of Timer/Counter1 Control Register A (TCCR1A)  */
#define TCCR1A       *((volatile u8 *)   0x4F)

/* Memory mapped address of Timer/Counter1 Control Register B (TCCR1B)  */
#define TCCR1B       *((volatile u8 *)   0x4E)

/* Memory mapped address of Timer/Counter1 Register (TCNT1H)  */
#define TCNT1H       *((volatile u8 *)   0x4D)

/* Memory mapped address of Timer/Counter1 Register (TCNT1L)  */
#define TCNT1L       *((volatile u8 *)   0x4C)

/* Memory mapped address of Output Compare Register 1 A (OCR1AH) */
#define OCR1AH       *((volatile u8 *)   0x4B)

/* Memory mapped address of Output Compare Register 1 A (OCR1AL) */
#define OCR1AL       *((volatile u8 *)   0x4A)

/* Memory mapped address of Output Compare Register 1 B (OCR1BH) */
#define OCR1BH       *((volatile u8 *)   0x49)

/* Memory mapped address of Output Compare Register 1 B (OCR1BL) */
#define OCR1BL       *((volatile u8 *)   0x48)

/* Memory mapped address of Input Capture Register 1 (ICR1H) */
#define ICR1H        *((volatile u8 *)   0x47)

/* Memory mapped address of Input Capture Register 1 (ICR1L) */
#define ICR1L        *((volatile u8 *)   0x46)

/* Memory mapped address of Timer/Counter Interrupt Mask Register (TIMSK) */
#define TIMSK        *((volatile u8 *)   0x59)

/* Memory mapped address of Timer/Counter Interrupt Flag Register (TIFR) */
#define TIFR         *((volatile u8 *)   0x58)

#endif