/****************************/
/*Author     : Ahmed Khalid */
/*Description: STD Library  */
/*Date       : 19/07/2019   */
/*Version    : 1.1v         */
/****************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f80;

typedef enum 
{
	OK,
	NOK,
	INDEX_OUT_OF_RANGE,
	NULL_POINTER
}ERRORSTATUS;


/* Pointer to function */
typedef void (*PF)(void);

/* NULL Pointer */
#define NULL  (void * )0

/* Void Pointer */

typedef void * VP;

#endif