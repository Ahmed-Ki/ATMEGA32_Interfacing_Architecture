/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for LCD */
/* Date        : 23 Aug 2019            */
/* Version     : 1.0v                   */
/****************************************/

#ifndef LCD_INT_H
#define LCD_INT_H

/**       SET OF COMMANDS        */
#define CLEAR_ALL        0x01
#define RM_CURSOR        0x0C
#define CURSOR_BLINK     0x0F
#define CURSOR_NO_BLINK  0x0E

#define CURSOR_MV_RIGHT  0x14 
#define CURSOR_MV_LEFT   0x10
#define DISP_MV_RIGHT    0x1C
#define DISP_MV_LEFT     0x18

#define DISP_ONE_LINE    0x30
#define DISP_TWO_LINES   0x38

#define GOTO_CGRAM       0x40
#define FIRST_LINE       0x80
#define SECOND_LINE      0xC0



/* Initialization function for LCD */
void LCD_voidInit(void);

/* Function to Send Commands to LCD Display */
void LCD_voidSendCmd(u8 u8CmdCpy);

/* Function to write a character on LCD */
void LCD_voidWriteChar(u8 u8CharCpy);

/* Function to clear LCD Display */
void LCD_voidClearDisplay(void);

/* Function to go to specific line and character on a LCD Display */
void LCD_voidGoToXY(u8 u8LineNbCpy, u8 u8CharNbCpy);

/* Write strings and terminates at \0 */
void LCD_voidWriteString(u8 *pu8StringCpy);

#endif