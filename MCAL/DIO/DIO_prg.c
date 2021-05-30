/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for DIO */
/* Date        : 17 Aug 2019          */
/* Version     : 1.0v                 */
/**************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"


/*********************************************/
/* Description : Initialization function     */
/*               it intializes the direction */
/*               of the PINS based on the    */
/*               cfg file                    */   
/*********************************************/

void DIO_voidInit(void)
{
    DDRA = CONC(DIO_u8PIN_DIR_7 ,DIO_u8PIN_DIR_6 ,DIO_u8PIN_DIR_5,DIO_u8PIN_DIR_4,DIO_u8PIN_DIR_3,DIO_u8PIN_DIR_2,DIO_u8PIN_DIR_1,DIO_u8PIN_DIR_0);
	DDRB = CONC(DIO_u8PIN_DIR_15,DIO_u8PIN_DIR_14,DIO_u8PIN_DIR_13,DIO_u8PIN_DIR_12,DIO_u8PIN_DIR_11,DIO_u8PIN_DIR_10,DIO_u8PIN_DIR_9,DIO_u8PIN_DIR_8);
	DDRC = CONC(DIO_u8PIN_DIR_23,DIO_u8PIN_DIR_22,DIO_u8PIN_DIR_21,DIO_u8PIN_DIR_20,DIO_u8PIN_DIR_19,DIO_u8PIN_DIR_18,DIO_u8PIN_DIR_17,DIO_u8PIN_DIR_16);
	DDRD = CONC(DIO_u8PIN_DIR_31,DIO_u8PIN_DIR_30,DIO_u8PIN_DIR_29,DIO_u8PIN_DIR_28,DIO_u8PIN_DIR_27,DIO_u8PIN_DIR_26,DIO_u8PIN_DIR_25,DIO_u8PIN_DIR_24);
	
}

/**********************************************/
/* Description: This function sets the PINs   */  
/*              value to HIGH or LOW          */       
/* INPUTS :                                   */
/*          u8PinNbCpy  : DIO_PIN_x           */
/*                      x in Range [0 .. 31]  */
/*          u8PinValueCpy : DIO_u8HIGH        */
/*                         DIO_u8LOW          */
/**********************************************/

void DIO_voidSetPinValue(u8 u8PinNbCpy , u8 u8PinValueCpy)
{
    if(u8PinNbCpy >= 0 && u8PinNbCpy <= 7)
	{
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTA , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(PORTA , u8PinNbCpy);
		}
	}
	else if(u8PinNbCpy >= 8 && u8PinNbCpy <= 15)
	{
		u8PinNbCpy %= 8;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTB , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(PORTB , u8PinNbCpy);
		}
	}
	else if(u8PinNbCpy >= 16 && u8PinNbCpy <= 23)
	{
		u8PinNbCpy %= 8;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTC , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(PORTC , u8PinNbCpy);
		}
	}
	else if(u8PinNbCpy >= 24 && u8PinNbCpy <= 31)
	{
		u8PinNbCpy %= 8;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTD , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(PORTD , u8PinNbCpy);
		}
	}
	else
	{
		
	}
}



/*********************************************/
/* Description: This function reads the      */
/*              PIN value                    */     
/* INPUT :                                   */
/*          u8PinNbCpy  : DIO_PIN_x          */
/*                      x in Range [0 .. 31] */
/*********************************************/

u8 DIO_u8GetPinValue(u8 u8PinNbCpy)
{
	u8 u8PinValueLoc = 0xFF;
	
	if(u8PinNbCpy >= 0 && u8PinNbCpy <= 7)
	{
		u8PinValueLoc = GET_BIT(PINA , u8PinNbCpy);
	}
	else if(u8PinNbCpy >= 8 && u8PinNbCpy <= 15)
	{
		u8PinNbCpy %= 8;
		
		u8PinValueLoc = GET_BIT(PINB , u8PinNbCpy);
		
	}
	else if(u8PinNbCpy >= 16 && u8PinNbCpy <= 23)
	{
		u8PinNbCpy %= 8;
		
		u8PinValueLoc = GET_BIT(PINC , u8PinNbCpy);
	}
	else if(u8PinNbCpy >= 24 && u8PinNbCpy <= 31)
	{
		u8PinNbCpy %= 8;
		
		u8PinValueLoc = GET_BIT(PIND , u8PinNbCpy);
	}
	else
	{
		
	}
	return u8PinValueLoc;
}

/*********************************************/
/* Description: This funtion toggles the     */
/*              value of the PIN             */
/*********************************************/

void DIO_voidTogglePinValue(u8 u8PinNbCpy)
{
	if(u8PinNbCpy >= 0 && u8PinNbCpy <= 7)
	{
		TOGGLE_BIT(PORTA, u8PinNbCpy);	
	}
	else if(u8PinNbCpy >= 8 && u8PinNbCpy <= 15)
	{
		u8PinNbCpy %= 8;
		TOGGLE_BIT(PORTB, u8PinNbCpy);
	}
	else if(u8PinNbCpy >= 16 && u8PinNbCpy <= 23)
	{
		u8PinNbCpy %= 8;
		TOGGLE_BIT(PORTC, u8PinNbCpy);
	}
	else if(u8PinNbCpy >= 24 && u8PinNbCpy <= 31)
	{
		u8PinNbCpy %= 8;
		TOGGLE_BIT(PORTD, u8PinNbCpy);
	}
	else
	{
		
	}
}

/*********************************************/
/* Description: This function changes the    */
/*              PIN direction in Run time    */
/*********************************************/

void DIO_voidSetPinDirectionRunTime(u8 u8PinNbCpy, u8 u8PinDirectionCpy)
{
	if(u8PinNbCpy >= 0 && u8PinNbCpy <= 7)
	{
		if(u8PinDirectionCpy == DIO_u8OUTPUT)
		{
			SET_BIT(DDRA , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(DDRA , u8PinNbCpy);
		}
	}
	else if(u8PinDirectionCpy >= 8 && u8PinNbCpy <= 15)
	{
		u8PinNbCpy %= 8;
		if(u8PinDirectionCpy == DIO_u8OUTPUT)
		{
			SET_BIT(DDRB , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(DDRB , u8PinNbCpy);
		}
	}
	else if(u8PinNbCpy >= 16 && u8PinNbCpy <= 23)
	{
		u8PinNbCpy %= 8;
		if(u8PinDirectionCpy == DIO_u8OUTPUT)
		{
			SET_BIT(DDRC , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(DDRC , u8PinNbCpy);
		}
	}
	else if(u8PinNbCpy >= 24 && u8PinNbCpy <= 31)
	{
		u8PinNbCpy %= 8;
		if(u8PinDirectionCpy == DIO_u8OUTPUT)
		{
			SET_BIT(DDRD , u8PinNbCpy);
		}
		else
		{
			CLEAR_BIT(DDRD , u8PinNbCpy);
		}
	}
	else
	{
		
	}
}

//implementation of functions and global variables
