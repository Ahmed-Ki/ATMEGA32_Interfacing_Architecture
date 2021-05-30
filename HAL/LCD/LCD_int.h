/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for LCD */
/* Date        : 23 Aug 2019            */
/* Version     : 1.0v                   */
/****************************************/


#ifndef LCD_INT_H
#define LCD_INT_H


void LCD_voidInit(void);


void LCD_voidSendCmd(u8 u8CmdCpy);


void LCD_voidWriteChar(u8 u8CharCpy);


void LCD_voidClearDisplay(void);    

void LCD_voidGoToXY(u8 u8LineNbCpy , u8 u8CharNbCpy );

void LCD_voidWriteString(u8 * pu8StringCpy );


#endif