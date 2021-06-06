/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for SEV */
/* Date        : 30 Aug 2019                */
/* Version     : 1.0V                       */
/********************************************/


#ifndef         SEV_CFG_H 
#define         SEV_CFG_H


/********************************************/
/* MODES  : COMMON_ANODE  ,  COMMON_CATHODE */
/********************************************/

#define SEV_u8MODE 			COMMON_ANODE

/*  SEV_u8MAX_NB is the number for Seven Segment Chips */

#define SEV_u8MAX_NB        2



/* Pin mapping for Seven Segment 1 */

#define SEV_0_PIN_A       DIO_PIN_0
#define SEV_0_PIN_B       DIO_PIN_1
#define SEV_0_PIN_C       DIO_PIN_2
#define SEV_0_PIN_D       DIO_PIN_3 
#define SEV_0_PIN_E       DIO_PIN_4
#define SEV_0_PIN_F       DIO_PIN_5
#define SEV_0_PIN_G       DIO_PIN_6
#define SEV_0_PIN_CM      DIO_PIN_7


/* Pin mapping for Seven Segment 2 */

#define SEV_1_PIN_A       DIO_PIN_10
#define SEV_1_PIN_B       DIO_PIN_11
#define SEV_1_PIN_C       DIO_PIN_12
#define SEV_1_PIN_D       DIO_PIN_13
#define SEV_1_PIN_E       DIO_PIN_14
#define SEV_1_PIN_F       DIO_PIN_15
#define SEV_1_PIN_G       DIO_PIN_16
#define SEV_1_PIN_CM      DIO_PIN_17


#endif