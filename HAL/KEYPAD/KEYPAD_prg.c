/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Program file for KEYPAD */
/* Date        : 24 Aug 2019             */
/* Version     : 1.0V                    */
/*****************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "KEYPAD_int.h"    
#include "KEYPAD_cfg.h"    
#include "KEYPAD_priv.h"    


/* Function to Initialize values for a 4x4 Keypad  */
void KEYPAD_voidInit(void)
{
    /* Activate pull up resistor by Setting INPUT Pins to HIGH */
    DIO_voidSetPinValue(KEYPAD_u8INPUT_0 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8INPUT_1 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8INPUT_2 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8INPUT_3 , DIO_u8HIGH);

    /* Initialize OUTPUT pins to HIGH */
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_0 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_1 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_2 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_3 , DIO_u8HIGH);
}



/* Function to Check for the pressed key and return its value */
u8 KEYPAD_u8GetPressedKey(void)
{

    u8 u8ReadKeyLoc;
    u8 u8ReturnValueLoc;


    /* Send first sequence to keypad */

    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_0 , DIO_u8LOW);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_1 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_2 , DIO_u8HIGH);
    DIO_voidSetPinValue(KEYPAD_u8OUTPUT_3 , DIO_u8HIGH);
    
    /* Read Input for first sequence */

    u8ReadKeyLoc = u8ReadKey();

    /* Switch case to check for which button is pressed on the keypad */

    switch (u8ReadKeyLoc)
    {

        case 0b00001110:
            u8ReturnValueLoc = BUTTON_0;
            break;

        case 0b00001101:
            u8ReturnValueLoc = BUTTON_1;
            break;

        case 0b00001011:
            u8ReturnValueLoc = BUTTON_2;
            break;

        case 0b00000111:
            u8ReturnValueLoc = BUTTON_3;
            break;

        default :
            u8ReturnValueLoc = 0xFF;    
        
    }
    
    if (u8ReturnValueLoc == 0xFF)
    {
        /* Send second sequence to keypad */

        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_0 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_1 , DIO_u8LOW);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_2 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_3 , DIO_u8HIGH);
    
        /* Read Input for second sequence */

        u8ReadKeyLoc = u8ReadKey();

          /* Switch case to check for which button is pressed on the keypad */

        switch (u8ReadKeyLoc)
        {

            case 0b00001110:
                u8ReturnValueLoc = BUTTON_4;
                break;

            case 0b00001101:
                u8ReturnValueLoc = BUTTON_5;
                break;

            case 0b00001011:
                u8ReturnValueLoc = BUTTON_6;
                break;

            case 0b00000111:
                u8ReturnValueLoc = BUTTON_7;
                break;

            default :
                u8ReturnValueLoc = 0xFF;    
        
        }
    }

    if (u8ReturnValueLoc == 0xFF)
    {
        /* Send third sequence to keypad */

        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_0 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_1 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_2 , DIO_u8LOW);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_3 , DIO_u8HIGH);
    
        /* Read Input for third sequence */
        u8ReadKeyLoc = u8ReadKey();

        /* Switch case to check for which button is pressed on the keypad */

        switch (u8ReadKeyLoc)
        {

            case 0b00001110:
                u8ReturnValueLoc = BUTTON_8;
                break;

            case 0b00001101:
                u8ReturnValueLoc = BUTTON_9;
                break;

            case 0b00001011:
                u8ReturnValueLoc = BUTTON_10;
                break;

            case 0b00000111:
                u8ReturnValueLoc = BUTTON_11;
                break;

            default :
                u8ReturnValueLoc = 0xFF;    
        
        }
    }

        if (u8ReturnValueLoc == 0xFF)
    {
        /* Send fourth sequence to keypad */

        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_0 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_1 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_2 , DIO_u8HIGH);
        DIO_voidSetPinValue(KEYPAD_u8OUTPUT_3 , DIO_u8LOW);
    
        /* Read Input for fourth sequence */

        u8ReadKeyLoc = u8ReadKey();

        /* Switch case to check for which button is pressed on the keypad */

        switch (u8ReadKeyLoc)
        {

            case 0b00001110:
                u8ReturnValueLoc = BUTTON_12;
                break;

            case 0b00001101:
                u8ReturnValueLoc = BUTTON_13;
                break;

            case 0b00001011:
                u8ReturnValueLoc = BUTTON_14;
                break;

            case 0b00000111:
                u8ReturnValueLoc = BUTTON_15;
                break;

            default :
                u8ReturnValueLoc = 0xFF;    
        
        }
    }   

    return u8ReturnValueLoc;    

}




static u8 u8ReadKey(void)
{
    u8 u8ReturnKeyLoc;
    
    u8ReturnKeyLoc  = DIO_u8GetPinValue(KEYPAD_u8INPUT_0);
    u8ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT_1) << 1;
    u8ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT_2) << 2;
    u8ReturnKeyLoc |= DIO_u8GetPinValue(KEYPAD_u8INPUT_3) << 3;

    return u8ReturnKeyLoc;

}


