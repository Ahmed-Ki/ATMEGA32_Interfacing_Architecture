/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Program file for TIMER2 */
/* Date        : 3 Oct 2021              */
/* Version     : 1.0V                    */
/*****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "TIMER2_int.h"
#include "TIMER2_cfg.h"
#include "TIMER2_priv.h"

PF TIMER2_PfCallBackAddrOV = NULL;

PF TIMER2_PfCallBackAddrCTC = NULL;

/*  Initialization function for TIMER2    */
/*  Sets operation Mode and Prescaler     */
/*  of TIMER2 according to choices in cfg */
void TIMER2_voidInit(void)
{
#if TIMER2_WAVEFORM_GENERATION_MODE == NORMAL
    CLEAR_BIT(TCCR2, 6);
    CLEAR_BIT(TCCR2, 3);
    /* Clear COM Bits */
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#elif TIMER2_WAVEFORM_GENERATION_MODE == PWM_PHASE_CORRECT
    SET_BIT(TCCR2, 6);
    CLEAR_BIT(TCCR2, 3);
#if TIMER2_COM_PHASE_CORRECT_PWM == NORMAL_OP
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#elif TIMER2_COM_PHASE_CORRECT_PWM == CLEAR_OC2_ON_COM_UP_COUNTING
    CLEAR_BIT(TCCR2, 4)
    SET_BIT(TCCR2, 5);
#elif TIMER2_COM_PHASE_CORRECT_PWM == SET_OC2_ON_COM_UP_COUNTING
    SET_BIT(TCCR2, 4);
    SET_BIT(TCCR2, 5);

/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#endif

#elif TIMER2_WAVEFORM_GENERATION_MODE == CTC
    CLEAR_BIT(TCCR2, 6);
    SET_BIT(TCCR2, 3);
#if TIMER2_COM_NON_PWM == NORMAL_OP
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#elif TIMER2_COM_NON_PWM == TOGGLE_OC2_ON_COM
    SET_BIT(TCCR2, 4)
    CLEAR_BIT(TCCR2, 5);
#elif TIMER2_COM_NON_PWM == CLEAR_OC2_ON_COM
    CLEAR_BIT(TCCR2, 4);
    SET_BIT(TCCR2, 5);
#elif TIMER2_COM_NON_PWM == SET_OC2_ON_COM
    SET_BIT(TCCR2, 4);
    SET_BIT(TCCR2, 5);

/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#endif

#elif TIMER2_WAVEFORM_GENERATION_MODE == FAST_PWM
    SET_BIT(TCCR2, 6);
    SET_BIT(TCCR2, 3);
#if TIMER2_COM_FAST_PWM == NORMAL_OP
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#elif TIMER2_COM_FAST_PWM == CLEAR_OC2_ON_COM_SET_TOP
    CLEAR_BIT(TCCR2, 4)
    SET_BIT(TCCR2, 5);
#elif TIMER2_COM_FAST_PWM == SET_OC2_ON_COM_CLEAR_TOP
    SET_BIT(TCCR2, 4);
    SET_BIT(TCCR2, 5);

/* Default is NORMAL_OP */
#else
    CLEAR_BIT(TCCR2, 4);
    CLEAR_BIT(TCCR2, 5);
#endif

/* Default is NORMAL */
#else
    CLEAR_BIT(TCCR2, 6);
    CLEAR_BIT(TCCR2, 3);
#endif

#if TIMER2_PRESCALER == TIMER2_DIV_BY_1
    SET_BIT(TCCR2, 0);
    CLEAR_BIT(TCCR2, 1);
    CLEAR_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_8
    CLEAR_BIT(TCCR2, 0);
    SET_BIT(TCCR2, 1);
    CLEAR_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_32
    SET_BIT(TCCR2, 0);
    SET_BIT(TCCR2, 1);
    CLEAR_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_64
    CLEAR_BIT(TCCR2, 0);
    CLEAR_BIT(TCCR2, 1);
    SET_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_128
    SET_BIT(TCCR2, 0);
    CLEAR_BIT(TCCR2, 1);
    SET_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_256
    CLEAR_BIT(TCCR2, 0);
    SET_BIT(TCCR2, 1);
    SET_BIT(TCCR2, 2);
#elif TIMER2_PRESCALER == TIMER2_DIV_BY_1024
    SET_BIT(TCCR2, 0);
    SET_BIT(TCCR2, 1);
    SET_BIT(TCCR2, 2);
/* Default: No clock source (Timer/Counter stopped) */
#else
    CLEAR_BIT(TCCR2, 0);
    CLEAR_BIT(TCCR2, 1);
    CLEAR_BIT(TCCR2, 2);
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
    TCNT2 = 0;
    /* Clear Output Compare Register */
    OCR2 = 0;
}

/* Enable Overflow Interrupt */
void TIMER2_voidInterruptOVEnable(void)
{
    SET_BIT(TIMSK, 6);
}

/* Disable Overflow Interrupt */
void TIMER2_voidInterruptOVDisable(void)
{
    CLEAR_BIT(TIMSK, 6);
}

/* Enable CTC Interrupt */
void TIMER2_voidInterruptCTCEnable(void)
{
    SET_BIT(TIMSK, 7);
}

/* Disable CTC Interrupt */
void TIMER2_voidInterruptCTCDisable(void)
{
    CLEAR_BIT(TIMSK, 7);
}

/* Reads the value of Timer/Counter register (TCNT2)      */
/* or the value of Output compare register (OC2) register */
/* depending on the mode configured in cfg                */
u8 TIMER2_voidReadTimerValue(void)
{
    u8 u8ValueLoc;
#if TIMER2_WAVEFORM_GENERATION_MODE == CTC
    u8ValueLoc = OCR2;
#else
    u8ValueLoc = TCNT2;
#endif

    return u8ValueLoc;
}

/* Sets the value of Timer/Counter (TCNT2) register */
void TIMER2_voidSetTimerValue(u8 u8ValueCpy)
{
    TCNT2 = u8ValueCpy;
}

/* Sets the value of Output Compare (OCR2) register */
void TIMER2_voidSetCompareValue(u8 u8ValueCpy)
{
    OCR2 = u8ValueCpy;
}

/* This is a CallBack function used in the Application layer        */
/* to write your ISR (Interrupt Service Routine) for Timer Overflow */
void TIMER2_voidOVCallBack(PF PfFuncAddrCpy)
{
    TIMER2_PfCallBackAddrOV = PfFuncAddrCpy;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for Timer CTC */
void TIMER2_voidCTCCallBack(PF PfFuncAddrCpy)
{
    TIMER2_PfCallBackAddrCTC = PfFuncAddrCpy;
}

void __vector_5(void) __attribute__((signal, used));
void __vector_5(void)
{
    if (TIMER2_PfCallBackAddrOV != NULL)
    {
        TIMER2_PfCallBackAddrOV();
    }
}

void __vector_4(void) __attribute__((signal, used));
void __vector_4(void)
{
    if (TIMER2_PfCallBackAddrCTC != NULL)
    {
        TIMER2_PfCallBackAddrCTC();
    }
}
