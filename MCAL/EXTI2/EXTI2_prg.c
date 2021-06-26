/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Program file for EXTI2 */
/* Date        : 6 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/



#include "STD_types.h"
#include "BIT_math.h"

#include "EXTI2_int.h"
#include "EXTI2_cfg.h"
#include "EXTI2_priv.h"



volatile PF EXTI2_PfCallBackAddr = NULL;


/* Initialize EXTI2 */
void EXTI2_voidInit(void)
{

    #if EXTI2_MODE == EXTI2_FALLING_EDGE
        CLEAR_BIT(MCUCSR,  6);

    /* Default mode is EXTI2_RISING_EDGE */
    #else
        SET_BIT(MCUCSR,  6);
    #endif

    /* Disable Interrupt */
    CLEAR_BIT(GICR,5);

    /* Clear INTF0 */
    SET_BIT(GIFR, 5);
}

/* Enable EXTI2 */
void EXTI2_voidEnable(void)
{
    SET_BIT(GICR, 5);
}

/* Disable EXTI2 */
void EXTI2_voidDisable(void)
{
    CLEAR_BIT(GICR, 5);
}


/* Changes Interrupt Sense Control of EXTI2 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI2_FALLING_EDGE              */
/*          EXTI2_RISING_EDGE               */

void EXTI2_voidModeChange(u8 u8ModeCpy)
{
    switch(u8ModeCpy)
    {
        case EXTI2_FALLING_EDGE:
        CLEAR_BIT(MCUCSR,  6);
        break;

        /* Default mode is EXTI2_RISING_EDGE */
        default:
        SET_BIT(MCUCSR,  6);
    }
}

void EXTI2_voidSetCallBack(PF PfFuncAddrCpy)
{
    EXTI2_PfCallBackAddr = PfFuncAddrCpy;
}

void __vector_3 (void) __attribute__((signal    ,   used));
void __vector_3 (void)
{
    if (EXTI2_PfCallBackAddr != NULL)
    {
        EXTI2_PfCallBackAddr();
    }

}

