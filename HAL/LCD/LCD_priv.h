/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for LCD */
/* Date        : 23 Aug 2019          */
/* Version     : 1.0v                 */
/**************************************/


#ifndef LCD_PRIV_H
#define LCD_PRIV_H

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



static void voidPutOnBus(u8 u8DataOrCmdCpy);




#endif