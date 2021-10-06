/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Program file for TIMER0 */
/* Date        : 15 Sep 2019             */
/* Version     : 1.0V                    */
/*****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "TIMER0_int.h"
#include "TIMER0_cfg.h"
#include "TIMER0_priv.h"

PF TIMER0_PfCallBackAddrOV = NULL;

PF TIMER0_PfCallBackAddrCTC = NULL;

/*  Initialization function for TIMER0    */
/*  Sets operation Mode and Prescaler     */
/*  of TIMER0 according to choices in cfg */
void TIMER0_voidInit(void)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == NORMAL
    CLEAR_BIT(TCCR0, 6);
    CLEAR_BIT(TCCR0, 3);
    /* CLEAR COM Bits for Normal Operation */
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);

#elif TIMER0_WAVEFORM_GENERATION_MODE == PWM_PHASE_CORRECT
    SET_BIT(TCCR0, 6);
    CLEAR_BIT(TCCR0, 3);
    /* TIMER0_COM_PHASE_CORRECT_PWM Operation Mode */
#if TIMER0_COM_PHASE_CORRECT_PWM == NORMAL_OP
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#elif TIMER0_COM_PHASE_CORRECT_PWM == CLEAR_OC0_ON_COM_UP_COUNTING
    CLEAR_BIT(TCCR0, 4)
    SET_BIT(TCCR0, 5);
#elif TIMER0_COM_PHASE_CORRECT_PWM == SET_OC0_ON_COM_UP_COUNTING
    SET_BIT(TCCR0, 4);
    SET_BIT(TCCR0, 5);
/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#endif
    /* End TIMER0_COM_PHASE_CORRECT_PWM Operation */

#elif TIMER0_WAVEFORM_GENERATION_MODE == CTC
    CLEAR_BIT(TCCR0, 6);
    SET_BIT(TCCR0, 3);
    /* TIMER0_COM_NON_PWM Operation Mode */
#if TIMER0_COM_NON_PWM == NORMAL_OP
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#elif TIMER0_COM_NON_PWM == TOGGLE_OC0_ON_COM
    SET_BIT(TCCR0, 4)
    CLEAR_BIT(TCCR0, 5);
#elif TIMER0_COM_NON_PWM == CLEAR_OC0_ON_COM
    CLEAR_BIT(TCCR0, 4);
    SET_BIT(TCCR0, 5);
#elif TIMER0_COM_NON_PWM == SET_OC0_ON_COM
    SET_BIT(TCCR0, 4);
    SET_BIT(TCCR0, 5);
/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#endif
    /* End TIMER0_COM_NON_PWM Operation */

#elif TIMER0_WAVEFORM_GENERATION_MODE == FAST_PWM
    SET_BIT(TCCR0, 6);
    SET_BIT(TCCR0, 3);
    /* TIMER0_COM_FAST_PWM Operation Mode */
#if TIMER0_COM_FAST_PWM == NORMAL_OP
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#elif TIMER0_COM_FAST_PWM == CLEAR_OC0_ON_COM_SET_TOP
    CLEAR_BIT(TCCR0, 4)
    SET_BIT(TCCR0, 5);
#elif TIMER0_COM_FAST_PWM == SET_OC0_ON_COM_CLEAR_TOP
    SET_BIT(TCCR0, 4);
    SET_BIT(TCCR0, 5);
/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR0, 4);
    CLEAR_BIT(TCCR0, 5);
#endif
    /* End TIMER0_COM_FAST_PWM Operation */

/* Default is NORMAL */
#else
    CLEAR_BIT(TCCR0, 6);
    CLEAR_BIT(TCCR0, 3);
#endif

#if TIMER0_PRESCALER == TIMER0_DIV_BY_1
    SET_BIT(TCCR0, 0);
    CLEAR_BIT(TCCR0, 1);
    CLEAR_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_DIV_BY_8
    CLEAR_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    CLEAR_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_DIV_BY_64
    SET_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    CLEAR_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_DIV_BY_256
    CLEAR_BIT(TCCR0, 0);
    CLEAR_BIT(TCCR0, 1);
    SET_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_DIV_BY_1024
    SET_BIT(TCCR0, 0);
    CLEAR_BIT(TCCR0, 1);
    SET_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_EXTERNAL_CLOCK_FALLING_EDGE
    CLEAR_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    SET_BIT(TCCR0, 2);
#elif TIMER0_PRESCALER == TIMER0_EXTERNAL_CLOCK_RISING_EDGE
    SET_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    SET_BIT(TCCR0, 2);

/* Default: No clock source (Timer/Counter stopped) */
#else
    CLEAR_BIT(TCCR0, 0);
    CLEAR_BIT(TCCR0, 1);
    CLEAR_BIT(TCCR0, 2);
#endif

    /* Disable Overflow Interrupts */
    CLEAR_BIT(TIMSK, 0);
    /* Disable Output Compare Interrupt */
    CLEAR_BIT(TIMSK, 1);
    /* Clear Overflow Flag */
    SET_BIT(TIFR, 0);
    /* Clear Output Compare Flag */
    SET_BIT(TIFR, 1);
    /* Clear Timer/Counter Register */
    TCNT0 = 0;
    /* Clear Output Compare Register */
    OCR0 = 0;
}

/* Enable Overflow Interrupt */
void TIMER0_voidInterruptOVEnable(void)
{
    SET_BIT(TIMSK, 0);
}

/* Disable Overflow Interrupt */
void TIMER0_voidInterruptOVDisable(void)
{
    CLEAR_BIT(TIMSK, 0);
}

/* Enable CTC Interrupt */
void TIMER0_voidInterruptCTCEnable(void)
{
    SET_BIT(TIMSK, 1);
}

/* Disable CTC Interrupt */
void TIMER0_voidInterruptCTCDisable(void)
{
    CLEAR_BIT(TIMSK, 1);
}

/* Reads the value of Timer/Counter register (TCNT0)      */
/* or the value of Output compare register (OC0) register */
/* depending on the mode configured in cfg                */
u8 TIMER0_voidReadTimerValue(void)
{
    u8 u8ValueLoc;
#if TIMER0_WAVEFORM_GENERATION_MODE == CTC
    u8ValueLoc = OCR0;
#else
    u8ValueLoc = TCNT0;
#endif

    return u8ValueLoc;
}

/* Sets the value of Timer/Counter (TCNT0) register */
void TIMER0_voidSetTimerValue(u8 u8ValueCpy)
{
    TCNT0 = u8ValueCpy;
}

/* Sets the value of Output Compare (OCR0) register */
void TIMER0_voidSetCompareValue(u8 u8ValueCpy)
{
    OCR0 = u8ValueCpy;
}

/* This is a CallBack function used in the Application layer        */
/* to write your ISR (Interrupt Service Routine) for Timer Overflow */
void TIMER0_voidOVCallBack(PF PfFuncAddrCpy)
{
    TIMER0_PfCallBackAddrOV = PfFuncAddrCpy;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for Timer CTC */
void TIMER0_voidCTCCallBack(PF PfFuncAddrCpy)
{
    TIMER0_PfCallBackAddrCTC = PfFuncAddrCpy;
}

void __vector_11(void) __attribute__((signal, used));
void __vector_11(void)
{
    if (TIMER0_PfCallBackAddrOV != NULL)
    {
        TIMER0_PfCallBackAddrOV();
    }
}

void __vector_10(void) __attribute__((signal, used));
void __vector_10(void)
{
    if (TIMER0_PfCallBackAddrCTC != NULL)
    {
        TIMER0_PfCallBackAddrCTC();
    }
}
