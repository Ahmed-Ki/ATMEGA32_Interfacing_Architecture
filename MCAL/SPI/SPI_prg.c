/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for SPI */
/* Date        : 12 Oct 2019          */
/* Version     : 1.0V                 */
/**************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"

PF SPI_PfCallBackAddrSTC = NULL;

/* Initialize SPI Master */
#if SPI_MODE == MASTER
void SPI_voidMasterInit(void)
{

    /* Enable Circuit */
    SET_BIT(SPCR, 6);

    /* Enable Master */
    SET_BIT(SPCR, 4);

#if SPI_CLOCK_POLARITY == IDLE_LOW
    CLEAR_BIT(SPCR, 3);
#elif SPI_CLOCK_POLARITY == IDLE_HIGH
    SET_BIT(SPCR, 3);
#endif

#if SPI_CLOCK_PHASE == ZERO
    CLEAR_BIT(SPCR, 2);
#elif SPI_CLOCK_PHASE == ONE
    SET_BIT(SPCR, 2);
#endif

#if SPI_CLOCK_RATE == FCPU_2
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_4
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_8
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_16
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_32
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_64
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_128
    SET_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);

#endif

#if SPI_DATA_ORDER == LSB_FIRST
    SET_BIT(SPCR, 5);
#elif SPI_DATA_ORDER == MSB_FIRST
    CLEAR_BIT(SPCR, 5);
#endif
}

/* Initialize SPI Slave */
#elif SPI_MODE == SLAVE
void SPI_voidSlaveInit(void)
{
    /* Enable Circuit */
    SET_BIT(SPCR, 6);

    /* Enable Slave */
    CLEAR_BIT(SPCR, 4);

#if SPI_CLOCK_POLARITY == IDLE_LOW
    CLEAR_BIT(SPCR, 3);
#elif SPI_CLOCK_POLARITY == IDLE_HIGH
    SET_BIT(SPCR, 3);
#endif

#if SPI_CLOCK_PHASE == ZERO
    CLEAR_BIT(SPCR, 2);
#elif SPI_CLOCK_PHASE == ONE
    SET_BIT(SPCR, 2);
#endif

#if SPI_CLOCK_RATE == FCPU_2
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_4
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_8
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_16
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_32
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    SET_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_64
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);
#elif SPI_CLOCK_RATE == FCPU_128
    SET_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    CLEAR_BIT(SPSR, 0);

#endif

#if SPI_DATA_ORDER == LSB_FIRST
    SET_BIT(SPCR, 5);
#elif SPI_DATA_ORDER == MSB_FIRST
    CLEAR_BIT(SPCR, 5);
#endif
}
#endif

/* Enable Interrupt */
void SPI_voidInterruptEnable(void)
{
    SET_BIT(SPCR, 7);
}

/* Disable Interrupt */
void SPI_voidInterruptDisable(void)
{
    CLEAR_BIT(SPCR, 7);
}

/* Enable SPI Circuit */
void SPI_voidEnable(void)
{
    SET_BIT(SPCR, 6);
}

/* Disable SPI Circuit */
void SPI_voidDisable(void)
{
    CLEAR_BIT(SPCR, 6);
}

/* Transmit and Receive Data Between Master and SLave */
u8 SPI_u8TransmitReceive(u8 u8DataCpy)
{
    SPDR = u8DataCpy;

    while (GET_BIT(SPSR, 7) == 0)
        ;

    return SPDR;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for SPI       */
/* Serial Transfer Complete                                    */
void SPI_voidCallBackSTC(PF PfFuncAddrCpy)
{
    SPI_PfCallBackAddrSTC = PfFuncAddrCpy;
}

void __vector_12(void) __attribute__((signal, used));
void __vector_12(void)
{
    if (SPI_PfCallBackAddrSTC != NULL)
    {
        SPI_PfCallBackAddrSTC();
    }
}
