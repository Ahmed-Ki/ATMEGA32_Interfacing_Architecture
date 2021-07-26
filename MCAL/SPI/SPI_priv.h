/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for SPI */
/* Date        : 12 Oct 2019          */
/* Version     : 1.0V                 */
/**************************************/


#ifndef SPI_PRIV_H
#define SPI_PRIV_H

#define MASTER  1
#define SLAVE   3

#define IDLE_LOW    5
#define IDLE_HIGH   7

#define ZERO    0
#define ONE     9

#define FCPU_2      11
#define FCPU_4      13
#define FCPU_8      15
#define FCPU_16     17
#define FCPU_32     19
#define FCPU_64     21
#define FCPU_128    23

#define LSB_FIRST   27
#define MSB_FIRST   29

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 0



/* Memory mapped address of SPI Control Register (SPCR) */
#define SPCR    *((volatile u8 *)   0x2D)     

/* Memory mapped address of SPI Status Register (SPSR) */
#define SPSR    *((volatile u8 *)   0x2E) 

/* Memory mapped address of SPI Data Register (SPDR) */
#define SPDR    *((volatile u8 *)   0x2F) 


#endif