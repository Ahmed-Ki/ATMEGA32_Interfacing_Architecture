/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for DIO */
/* Date        : 17 Aug 2019                */
/* Version     : 1.0v                       */
/********************************************/


#ifndef DIO_CFG_H
#define DIO_CFG_H

/***************************************************/
/* Description : In this file you can configure    */
/*               the direction of each PIN either  */
/*               INPUT OR OUTPUT.                  */
/*               DIO_u8OUTPUT to set direction to  */
/*               OUTPUT.                           */
/*               DIO_u8INPUT to set direction to   */
/*               INPUT.                            */
/***************************************************/                 

/* Description : PORT A DIRECTIONS INPUT OR OUTPUT */  
/*                 FROM PIN 0 -> PIN 7             */
#define DIO_u8PIN_DIR_0    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_1    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_2    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_3    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_4    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_5    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_6    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_7    DIO_u8OUTPUT

/* Description : PORT B DIRECTIONS INPUT OR OUTPUT  */
/*                 FROM PIN 8 -> PIN 15             */

#define DIO_u8PIN_DIR_8    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_9    DIO_u8OUTPUT
#define DIO_u8PIN_DIR_10   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_11   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_12   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_13   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_14   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_15   DIO_u8OUTPUT

/* Description : PORT C DIRECTIONS INPUT OR OUTPUT  */ 
/*                 FROM PIN 16 -> PIN 23            */

#define DIO_u8PIN_DIR_16   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_17   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_18   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_19   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_20   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_21   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_22   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_23   DIO_u8OUTPUT

/* Description : PORT D DIRECTIONS INPUT OR OUTPUT   */ 
/*                 FROM PIN 24 -> PIN 31             */

#define DIO_u8PIN_DIR_24   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_25   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_26   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_27   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_28   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_29   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_30   DIO_u8OUTPUT
#define DIO_u8PIN_DIR_31   DIO_u8OUTPUT

#endif






//configuration available for the user