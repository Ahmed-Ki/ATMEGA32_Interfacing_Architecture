/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Program file for EXTI1 */
/* Date        : 6 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/



#include "STD_types.h"
#include "BIT_math.h"

#include "EXTI1_int.h"
#include "EXTI1_cfg.h"
#include "EXTI1_priv.h"



PF EXTI1_PfCallBackAddr = NULL;


/* Initialize EXTI1 */
void EXTI1_voidInit(void)
{
    #if EXTI1_MODE == EXTI1_IOC
        SET_BIT(MCUCR,  2);
        CLEAR_BIT(MCUCR,3);

    #elif EXTI1_MODE == EXTI1_FALLING_EDGE
        CLEAR_BIT(MCUCR,  2);
        SET_BIT(MCUCR,    3);

    #elif EXTI1_MODE == EXTI1_RISING_EDGE
        SET_BIT(MCUCR,  2);
        SET_BIT(MCUCR,  3);

    /* Default mode is EXTI1_LOW_LEVEL */
    #else
        CLEAR_BIT(MCUCR,  2);
        CLEAR_BIT(MCUCR,  3);

    #endif

    /* Disable Interrupt */
    CLEAR_BIT(GICR,7);

    /* Clear INTF0 */
    SET_BIT(GIFR, 7);
}

/* Enable EXTI1 */
void EXTI1_voidEnable(void)
{
    SET_BIT(GICR, 7);
}

/* Disable EXTI1 */
void EXTI1_voidDisable(void)
{
    CLEAR_BIT(GICR, 7);
}


/* Changes Interrupt Sense Control of EXTI1 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI1_LOW_LEVEL                 */          
/*          EXTI1_IOC                       */
/*          EXTI1_FALLING_EDGE              */
/*          EXTI1_RISING_EDGE               */
/********************************************/   
/*         IOC: Interrupt On Change         */
void EXTI1_voidModeChange(u8 u8ModeCpy)
{
    switch(u8ModeCpy)
    {
        case EXTI1_IOC:
        SET_BIT(MCUCR,  2);
        CLEAR_BIT(MCUCR,3);
        break;

        case EXTI1_FALLING_EDGE:
        CLEAR_BIT(MCUCR,  2);
        SET_BIT(MCUCR,    3);
        break;

        case EXTI1_RISING_EDGE:
        SET_BIT(MCUCR,  2);
        SET_BIT(MCUCR,  3);
        break;

        /* Default mode is EXTI1_LOW_LEVEL */
        default:
        CLEAR_BIT(MCUCR,  2);
        CLEAR_BIT(MCUCR,  3);

    }
}


/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void EXTI1_voidSetCallBack(PF PfFuncAddrCpy)
{
    EXTI1_PfCallBackAddr = PfFuncAddrCpy;
}

void __vector_2 (void) __attribute__((signal    ,   used));
void __vector_2 (void)
{
    if (EXTI1_PfCallBackAddr != NULL)
    {
        EXTI1_PfCallBackAddr();
    }

}

