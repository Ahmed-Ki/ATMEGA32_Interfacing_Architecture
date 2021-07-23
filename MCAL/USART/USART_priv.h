/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for USART */
/* Date        : 17 Oct 2019            */
/* version     : 1.0V                   */
/****************************************/


#ifndef USART_PRIV_H
#define USART_PRIV_H


#define ASYNCHRONOUS    1
#define SYNCHRONOUS     3

#define NORMAL_SPEED_MODE   5
#define DOUBLE_SPEED_MODE   7

#define DISABLED    9 
#define EVEN        11
#define ODD         13

#define ONE_BIT     15
#define TWO_BITS    17

#define RISING	    19
#define FALLING     21



/* Memory mapped address of USART Control and Status Register A (UCSRA) */
#define UCSRA 		*((volatile u8 *)   0x2B)

/* Memory mapped address of USART Control and Status Register B (UCSRB) */	
#define UCSRB 		*((volatile u8 *)   0x2A)

/* Memory mapped address of USART Control and Status Register C (UCSRC) */
#define UCSRC 		*((volatile u8 *)   0x40)

/* Memory mapped address of USART Baud Rate Register  (UBRRH) */
#define UBRRH 		*((volatile u8 *)   0x40)

/* Memory mapped address of USART Baud Rate Register (UBRRL) */
#define UBRRL 		*((volatile u8 *)   0x29)

/* Memory mapped address of USART I/O Data Register (UDR) */
#define UDR 		*((volatile u8 *)   0x2C)


#endif