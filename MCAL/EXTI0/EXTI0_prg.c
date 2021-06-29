/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Program file for EXTI0 */
/* Date        : 6 Sep 2019             */
/* Version     : 1.0V                   */
/****************************************/



#include "STD_types.h"
#include "BIT_math.h"

#include "EXTI0_int.h"
#include "EXTI0_cfg.h"
#include "EXTI0_priv.h"



volatile PF EXTI0_PfCallBackAddr = NULL;


/* Initialize EXTI0 */
void EXTI0_voidInit(void)
{
    #if EXTI0_MODE == EXTI0_IOC
        SET_BIT(MCUCR,  0);
        CLEAR_BIT(MCUCR,1);

    #elif EXTI0_MODE == EXTI0_FALLING_EDGE
        CLEAR_BIT(MCUCR,  0);
        SET_BIT(MCUCR,    1);

    #elif EXTI0_MODE == EXTI0_RISING_EDGE
        SET_BIT(MCUCR,  0);
        SET_BIT(MCUCR,  1);

    /* Default mode is EXTI0_LOW_LEVEL */
    #else
        CLEAR_BIT(MCUCR,  0);
        CLEAR_BIT(MCUCR,  1);

    #endif

    /* Disable Interrupt */
    CLEAR_BIT(GICR,6);

    /* Clear INTF0 */
    SET_BIT(GIFR, 6);
}

/* Enable EXTI0 */
void EXTI0_voidEnable(void)
{
    SET_BIT(GICR, 6);
}

/* Disable EXTI0 */
void EXTI0_voidDisable(void)
{
    CLEAR_BIT(GICR, 6);
}


/* Changes Interrupt Sense Control of EXTI0 */
/* Input: u8ModeCpy accepts one of          */
/*        the following modes               */
/* Modes:                                   */
/*          EXTI0_LOW_LEVEL                 */          
/*          EXTI0_IOC                       */
/*          EXTI0_FALLING_EDGE              */
/*          EXTI0_RISING_EDGE               */
/********************************************/   
/*         IOC: Interrupt On Change         */
void EXTI0_voidModeChange(u8 u8ModeCpy)
{
    switch(u8ModeCpy)
    {
        case EXTI0_IOC:
        SET_BIT(MCUCR,  0);
        CLEAR_BIT(MCUCR,1);
        break;

        case EXTI0_FALLING_EDGE:
        CLEAR_BIT(MCUCR,  0);
        SET_BIT(MCUCR,    1);
        break;

        case EXTI0_RISING_EDGE:
        SET_BIT(MCUCR,  0);
        SET_BIT(MCUCR,  1);
        break;

        /* Default mode is EXTI0_LOW_LEVEL */
        default:
        CLEAR_BIT(MCUCR,  0);
        CLEAR_BIT(MCUCR,  1);

    }
}

/* This is a CallBack function used in the Application layer to write your ISR (Interrupt Service Routine) */
void EXTI0_voidSetCallBack(PF PfFuncAddrCpy)
{
    EXTI0_PfCallBackAddr = PfFuncAddrCpy;
}

void __vector_1 (void) __attribute__((signal    ,   used));
void __vector_1 (void)
{
    if (EXTI0_PfCallBackAddr != NULL)
    {
        EXTI0_PfCallBackAddr();
    }

}

