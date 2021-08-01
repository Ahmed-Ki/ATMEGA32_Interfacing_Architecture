/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for I2C */
/* Date        : 18 Oct 2019            */
/* Version     : 1.0V                   */
/****************************************/

#ifndef I2C_INT_H
#define I2C_INT_H

typedef enum
{
    /* Master Transmitter Mode */
    Start_Condition_Tx = 0x08,
    Repeated_Start_Condition_Tx = 0x10,
    SLA_W_Tx_ACK_Rx = 0x18,
    SLA_W_Tx_NO_ACK_Rx = 0x20,
    Data_Tx_ACK_Rx = 0x28,
    Data_Tx_NO_ACK_Rx = 0x30,
    Arbritration_Lost_In_SLA_W_Or_DATA = 0x38,
    /* End Master Transmitter Mode */

    /* Master Receiver Mode */
    SLA_R_Tx_ACK_Rx = 0x40,
    SLA_R_Tx_NO_ACK_Rx = 0x48,
    Data_Rx_ACK_Return = 0x50,
    Data_Rx_NO_ACK_Return = 0x58,
    /* End Master Receiver Mode */

    /* Slave Receiver Mode */
    Own_SLA_W_Rx_ACK_Return = 0x60,
    Arbritration_Lost_In_SLA_RW_As_Master_Own_SLA_W_Rx_ACK_Return = 0x68,
    General_Call_Addr_Rx_Ack_Return = 0x70,
    Arbritration_Lost_In_SLA_RW_As_Master_General_Call_Addr_Rx_ACK_Return = 0x78,
    Previously_Addr_With_Own_SLA_W_Data_Rx_ACK_Retrun = 0x80,
    Previously_Addr_With_Own_SLA_W_Data_Rx_NO_ACK_Retrun = 0x88,
    Previously_Addr_With_General_Call_Data_Rx_ACK_Retrun = 0x90,
    Previously_Addr_With_General_Call_Data_Rx_NO_ACK_Retrun = 0x98,
    Stop_Condition_Or_Repeated_Start_Condition_Rx_While_Still_Addr_As_SLA = 0xA0,
    /* End Slave Receiver */

    /* Slave Transmitter Mode */
    Own_SLA_R_Rx_ACK_Return = 0xA8,
    Arbritration_Lost_In_SLA_RW_As_Master_Own_SLA_R_Rx_ACK_Return = 0xB0,
    Data_In_TWDR_Tx_ACK_Rx = 0xB8,
    Data_In_TWDR_Tx_NO_ACK_Rx = 0xC0,
    Last_Data_Byte_in_TWDR_Tx_ACK_Rx = 0xC8
    /* End Slave Transmitter */

} tenuI2C_Check;

/* Initialize I2C/TWI */
void TWI_voidInit(void);

/* Set My I2C/TWI Slave Address */
void TWI_voidSetMyAddr(u8 AddrCpy);

/* Send Start Condition */
void TWI_voidSendStartCondition(void);

/* Send Stop Condition */
void TWI_voidSendStopCondition(void);

/* Send Data Byte or Slave Address + R/W */
void TWI_voidSendByte(u8 ByteCpy);

/* Receive Byte With No Acknowledgment  */
u8 TWI_u8ReceiveByteWithNoAck(void);

/* Receive Byte With Acknowledgment  */
u8 TWI_u8ReceiveByteWithAck(void);

/* Enable Interrupt */
void TWI_voidInterruptEnable(void);

/* Enum to Check Status of I2C/TWI Master/Slave */
ERRORSTATUS TWI_enuCheckStatus(tenuI2C_Check StatusCpy);

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for TWI       */
void TWI_voidCallBackTWI(PF PfFuncAddrCpy);


#endif