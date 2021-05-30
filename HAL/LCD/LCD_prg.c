/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for LCD */
/* Date        : 23 Aug 2019          */
/* Version     : 1.0v                 */
/**************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"
#include <util/delay.h>

#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"





void LCD_voidInit(void)
{
    /* Latch Low */
    DIO_voidSetPinValue(LCD_EN  , DIO_u8LOW);

    /* wait 35 ms */
    _delay_ms(35);

    /* Function Set */

    LCD_voidSendCmd(0x38);

    /* wait 1ms */
    _delay_ms(1);

    /* Display ON/OFF Control */
    LCD_voidSendCmd(0x0F);

    /* wait 1 ms */
    _delay_ms(1);

    /* Display Clear */
    LCD_voidSendCmd(0x01);

    /* Wait 2ms */
    _delay_ms(2);
    
    /* Entry Mode Set */
    LCD_voidSendCmd(0x06);

    /* wait 1ms */
    _delay_ms(1);
}


void LCD_voidSendCmd(u8 u8CmdCpy)
{
    /* RS = LOW Command Register*/
    DIO_voidSetPinValue(LCD_RS , DIO_u8LOW); 
    
    /* Put value on bus */
    voidPutOnBus(u8CmdCpy);

}


void LCD_voidWriteChar(u8 u8CharCpy)
{
    /* RS = HIGH Data Register */
    DIO_voidSetPinValue(LCD_RS , DIO_u8HIGH); 

    /* Put value on bus */
    voidPutOnBus(u8CharCpy);
}



static void voidPutOnBus(u8 u8DataOrCmdCpy)
{
    /*  Read/Write Value = Low for Write */
    DIO_voidSetPinValue(LCD_RW  , DIO_u8LOW);


    DIO_voidSetPinValue(LCD_DATA_0    , GET_BIT(u8DataOrCmdCpy  , 0) );
    DIO_voidSetPinValue(LCD_DATA_1    , GET_BIT(u8DataOrCmdCpy  , 1) );
    DIO_voidSetPinValue(LCD_DATA_2    , GET_BIT(u8DataOrCmdCpy  , 2) );
    DIO_voidSetPinValue(LCD_DATA_3    , GET_BIT(u8DataOrCmdCpy  , 3) );
    DIO_voidSetPinValue(LCD_DATA_4    , GET_BIT(u8DataOrCmdCpy  , 4) );
    DIO_voidSetPinValue(LCD_DATA_5    , GET_BIT(u8DataOrCmdCpy  , 5) );
    DIO_voidSetPinValue(LCD_DATA_6    , GET_BIT(u8DataOrCmdCpy  , 6) );
    DIO_voidSetPinValue(LCD_DATA_7    , GET_BIT(u8DataOrCmdCpy  , 7) );
   

    /* Latch = High */
    DIO_voidSetPinValue(LCD_EN  , DIO_u8HIGH);

    /* wait 1ms */
    _delay_ms(1);

    /* Latch = Low */
    DIO_voidSetPinValue(LCD_EN  , DIO_u8LOW);

}

/* Function to clear LCD Display */

void LCD_voidClearDisplay(void)    
{
    LCD_voidSendCmd(0x01);

    _delay_ms(2);
}


/* Function to go to specific line and character on a LCD Display */

void LCD_voidGoToXY(u8 u8LineNbCpy , u8 u8CharNbCpy)
{
    if(u8LineNbCpy == 1)
    {
        LCD_voidSendCmd((LCD_FIRST_LINE + u8CharNbCpy));

    }
    else if(u8LineNbCpy == 2)
    {
        LCD_voidSendCmd((LCD_SECOND_LINE + u8CharNbCpy));

    }

    else
    {

    }

}

/* Function to write strings */

/* Write strings anf end it with \0 to terminate */

void LCD_voidWriteString(u8 * pu8StringCpy)
{
    u8 Loc_u8Counter = 0 ;
	
	while(pu8StringCpy[Loc_u8Counter] !='\0')
	{
		LCD_voidWriteChar(pu8StringCpy[Loc_u8Counter]);
		Loc_u8Counter++;		
	}

}

