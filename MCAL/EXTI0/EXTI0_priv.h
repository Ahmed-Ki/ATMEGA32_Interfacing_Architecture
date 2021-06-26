/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for EXTI0 */
/* Date        : 6 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/


#ifndef EXTI0_PRIV_H
#define EXTI0_PRIV_H

/* Memory mapped address of MCU Control Register */
#define MCUCR   *((volatile u8 *) 0x55)


/* Memory mapped address of General Interrupt Control Register */
#define GICR    *((volatile u8 *) 0x5B)


/* Memory mapped address of General Interrupt Flag Register */
#define GIFR    *((volatile u8 *) 0x5A)





#endif