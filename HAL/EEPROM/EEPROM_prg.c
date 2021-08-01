/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Program file for EEPROM */
/* Date        : 19 Oct 2019             */
/* Version     : 1.0V                    */
/*****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "I2C_int.h"

#include "EEPROM_int.h"
#include "EEPROM_cfg.h"
#include "EEPROM_priv.h"

/* Initialize EEPROM */
void EEPROM_voidInit(void)
{
    TWI_voidInit();
}

/* Write a Byte to EEPROM */
ERRORSTATUS EEPROM_enuWriteByte(u16 u16LocationCpy, u8 u8DataCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;
    /* EEPROM Slave Address + Write  */
    u8 EEPROM_SLA_W = 0b10100000;
    /* EEPROM_A0 and EEPROM_A1 bits are used to determine   */
    /*  which block within  selected EEPROM chip to address */
    u8 EEPROM_A0 = GET_BIT(u16LocationCpy, 8);
    u8 EEPROM_A1 = GET_BIT(u16LocationCpy, 9);
    /* EEPROM_A2 is used to select EEPROM Chip */
    u8 EEPROM_A2 = GET_BIT(u16LocationCpy, 10);
    /* Add values of EEPROM_A0/A1/A2 bits in EEPROM_SLA_W */
    EEPROM_SLA_W |= ((EEPROM_A0 << 1) | (EEPROM_A1 << 2) | (EEPROM_A2 << 3));

    TWI_voidSendStartCondition();

    if (enuErrorStatLoc == TWI_enuCheckStatus(Start_Condition_Tx))
    {
        TWI_voidSendByte(EEPROM_SLA_W);

        if (enuErrorStatLoc == TWI_enuCheckStatus(SLA_W_Tx_ACK_Rx))
        {

            TWI_voidSendByte((u8)u16LocationCpy);

            if (enuErrorStatLoc == TWI_enuCheckStatus(Data_Tx_ACK_Rx))
            {
                TWI_voidSendByte(u8DataCpy);
                if (enuErrorStatLoc == TWI_enuCheckStatus(Data_Tx_ACK_Rx))
                {
                    TWI_voidSendStopCondition();
                }
            }
        }
    }
    else
    {
        enuErrorStatLoc = NOK;
    }
    return enuErrorStatLoc;
}

/* Read a Byte from EEPROM */
u8 EEPROM_u8ReadByte(u16 u16LocationCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;
    u8 u8ReadByteValLoc = 0;
    /* EEPROM Slave Address + Write  */
    u8 EEPROM_SLA_W = 0b10100000;
    u8 EEPROM_SLA_R = 0;
    /* EEPROM_A0 and EEPROM_A1 bits are used to determine   */
    /*  which block within  selected EEPROM chip to address */
    u8 EEPROM_A0 = GET_BIT(u16LocationCpy, 8);
    u8 EEPROM_A1 = GET_BIT(u16LocationCpy, 9);
    /* EEPROM_A2 is used to select EEPROM Chip */
    u8 EEPROM_A2 = GET_BIT(u16LocationCpy, 10);
    /* Add values of EEPROM_A0/A1/A2 bits in EEPROM_SLA_W */
    EEPROM_SLA_W |= ((EEPROM_A0 << 1) | (EEPROM_A1 << 2) | (EEPROM_A2 << 3));
    /* EEPROM Slave Address + Read  */
    EEPROM_SLA_R = EEPROM_SLA_W + 1;
    TWI_voidSendStartCondition();
    if (enuErrorStatLoc == TWI_enuCheckStatus(Start_Condition_Tx))
    {
        TWI_voidSendByte(EEPROM_SLA_W);
        if (enuErrorStatLoc == TWI_enuCheckStatus(SLA_W_Tx_ACK_Rx))
        {
            TWI_voidSendByte((u8)u16LocationCpy);
            if (enuErrorStatLoc == TWI_enuCheckStatus(Data_Tx_ACK_Rx))
            {
                TWI_voidSendStartCondition();
                if (enuErrorStatLoc == TWI_enuCheckStatus(Repeated_Start_Condition_Tx))
                {
                    TWI_voidSendByte(EEPROM_SLA_R);
                    if (enuErrorStatLoc == TWI_enuCheckStatus(SLA_R_Tx_ACK_Rx))
                    {
                        u8ReadByteValLoc = TWI_u8ReceiveByteWithNoAck();
                        TWI_voidSendStopCondition();
                    }
                }
            }
        }
    }
    else
    {
        enuErrorStatLoc = NOK;
        u8ReadByteValLoc = enuErrorStatLoc;
    }

    return u8ReadByteValLoc;
}