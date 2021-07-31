/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for I2C */
/* Date        : 18 Oct 2019          */
/* Version     : 1.0V                 */
/**************************************/


#ifndef I2C_PRIV_H
#define I2C_PRIV_H

/* TWCR Bits */

#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

/* TWSR Bits */

#define TWPS0   0
#define TWPS1   1


#define ENABLED 1
#define DISABLED 0







/* Memory mapped address of TWI Bit Rate Register (TWBR) */
#define TWBR    *((volatile u8 *)   0x20)

/* Memory mapped address of TWI Control Register (TWCR) */
#define TWCR    *((volatile u8 *)   0x56)

/* Memory mapped address of TWI Status Register (TWSR) */
#define TWSR    *((volatile u8 *)   0x21)

/* Memory mapped address of TWI Data Register (TWDR) */
#define TWDR    *((volatile u8 *)   0x23)

/* Memory mapped address of TWI (Slave) Address Register (TWAR) */
#define TWAR    *((volatile u8 *)   0x22)





#endif