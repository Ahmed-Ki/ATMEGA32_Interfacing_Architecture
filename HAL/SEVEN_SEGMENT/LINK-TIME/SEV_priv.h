/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for SEV */
/* Date        : 30 Aug 2019          */
/* Version     : 1.0V                 */
/**************************************/


#ifndef         SEV_PRIV_H 
#define         SEV_PRIV_H


#define COMMON_ANODE       0X55
#define COMMON_CATHODE     0xAA    


/* Struct to define PINS for Seven Segment */

typedef struct
{
	u8 u8PIN_A  ;
	u8 u8PIN_B  ;
	u8 u8PIN_C  ;
	u8 u8PIN_D  ;
	u8 u8PIN_E  ;
	u8 u8PIN_F  ;
	u8 u8PIN_G  ;
	u8 u8PIN_CM ;
	
}tstr7Seg;


extern tstr7Seg astr7SegCfg[SEV_u8MAX_NB];


#endif