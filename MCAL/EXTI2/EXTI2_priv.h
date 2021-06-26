/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for EXTI2 */
/* Date        : 6 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/


#ifndef EXTI2_PRIV_H
#define EXTI2_PRIV_H


/* Memory mapped address of MCU Control and Status Register */
#define MCUCSR   *((volatile u8 *) 0x54)


/* Memory mapped address of General Interrupt Control Register */
#define GICR     *((volatile u8 *) 0x5B)


/* Memory mapped address of General Interrupt Flag Register */
#define GIFR     *((volatile u8 *) 0x5A)




#endif