/**********************************************************/
/* Author     : Ahmed Khalid		                      */
/* Description: BIT_math is a library to manipulate a bit */
/* Date       : 26/07/2019                                */
/* Version    : 1.0v                                      */
/**********************************************************/


#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg&=~(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))
#define GET_BIT(reg,bit) ((reg>>bit)&(0x01))

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)       CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif

