/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Program file for I2C   */
/* Date        : 18 Oct 2019            */
/* Version     : 1.0V                   */
/****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "I2C_int.h"
#include "I2C_cfg.h"
#include "I2C_priv.h"

PF TWI_PfCallBackAddrTWI = NULL;

/* Initialize I2C/TWI */
void TWI_voidInit(void)
{

    TWCR = (1 << TWEN);

#if TWI_PRESCALER == 1
    CLEAR_BIT(TWSR, TWPS0);
    CLEAR_BIT(TWSR, TWPS1);
#elif TWI_PRESCALER == 4
    SET_BIT(TWSR, TWPS0);
    CLEAR_BIT(TWSR, TWPS1);
#elif TWI_PRESCALER == 16
    CLEAR_BIT(TWSR, TWPS0);
    SET_BIT(TWSR, TWPS1);
#elif TWI_PRESCALER == 64
    SET_BIT(TWSR, TWPS0);
    SET_BIT(TWSR, TWPS1);
#endif

    TWBR = TWI_TWBR_VALUE;
}

/* Set My I2C/TWI Slave Address */
void TWI_voidSetMyAddr(u8 AddrCpy)
{
#if TWI_GENERAL_CALL == ENABLED
    TWAR = (1 << 0);
    TWAR &= 0x01;
    TWAR |= (AddrCpy << 1);
#elif TWI_GENERAL_CALL == DISABLED
    TWAR &= 0x00;
    TWAR |= (AddrCpy << 1);
#endif
}

/* Send Start Condition */
void TWI_voidSendStartCondition(void)
{
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (GET_BIT(TWCR, TWINT) == 0)
        ;
}

/* Send Stop Condition */
void TWI_voidSendStopCondition(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/* Send Data Byte or Slave Address + R/W */
void TWI_voidSendByte(u8 ByteCpy)
{
    TWDR = ByteCpy;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0)
        ;
}

/* Receive Byte With No Acknowledgment  */
u8 TWI_u8ReceiveByteWithNoAck(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0)
        ;
    return TWDR;
}

/* Receive Byte With Acknowledgment  */
u8 TWI_u8ReceiveByteWithAck(void)
{

    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (GET_BIT(TWCR, TWINT) == 0)
        ;
    return TWDR;
}

/* Enable Interrupt */
void TWI_voidInterruptEnable(void)
{
    TWCR |= (1 << TWIE);
}

/* Enum to Check Status of I2C/TWI Master/Slave */
ERRORSTATUS TWI_enuCheckStatus(tenuI2C_Check StatusCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;

    if (StatusCpy == (TWSR & 0xF8))
    {
        enuErrorStatLoc = OK;
    }
    else
    {
        enuErrorStatLoc = NOK;
    }
    return enuErrorStatLoc;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for TWI       */
void TWI_voidCallBackTWI(PF PfFuncAddrCpy)
{
    TWI_PfCallBackAddrTWI = PfFuncAddrCpy;
}

void __vector_19(void) __attribute__((signal, used));
void __vector_19(void)
{
    if (TWI_PfCallBackAddrTWI != NULL)
    {
        TWI_PfCallBackAddrTWI();
    }
}
