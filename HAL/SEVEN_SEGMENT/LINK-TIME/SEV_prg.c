/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for SEV */
/* Date        : 30 Aug 2019          */
/* Version     : 1.0V                 */
/**************************************/


#include    "STD_types.h"
#include    "BIT_math.h"

#include    "DIO_int.h"

#include    "SEV_int.h"
#include    "SEV_cfg.h"
#include    "SEV_priv.h"


/* Function to display numbers from 0 --> 9 on a Seven Segment */

ERRORSTATUS SEV_enuDisplayNb(u8 u8ChipNbCpy, u8 u8NbCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;
   
    #if SEV_u8MODE == COMMON_ANODE
    
    /* Hex value for numbers 0 --> 9 for COMMON_ANODE */

    u8 seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

    #else

    /* Hex value for numbers 0 --> 9 for COMMON_CATHODE */
   
    u8 seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    #endif

    if (u8ChipNbCpy > SEV_u8MAX_NB || u8NbCpy > 9)
    {
        enuErrorStatLoc = INDEX_OUT_OF_RANGE;
    }

    else
    {
        DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_A  , GET_BIT(seg[u8NbCpy] , 0  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_B  , GET_BIT(seg[u8NbCpy] , 1  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_C  , GET_BIT(seg[u8NbCpy] , 2  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_D  , GET_BIT(seg[u8NbCpy] , 3  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_E  , GET_BIT(seg[u8NbCpy] , 4  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_F  , GET_BIT(seg[u8NbCpy] , 5  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_G  , GET_BIT(seg[u8NbCpy] , 6  ) );
		DIO_voidSetPinValue( astr7SegCfg[u8ChipNbCpy].u8PIN_CM , GET_BIT(seg[u8NbCpy] , 7  ) );
		
    }

    return enuErrorStatLoc;

}
