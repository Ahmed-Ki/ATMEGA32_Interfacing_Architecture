/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for SPI */
/* Date        : 12 Oct 2019            */
/* Version     : 1.0V                   */
/****************************************/


#ifndef SPI_INT_H
#define SPI_INT_H

/* Initialize SPI Master */
void SPI_voidMasterInit(void);

/* Initialize SPI Slave */
void SPI_voidSlaveInit(void);

/* Enable Interrupt */
void SPI_voidInterruptEnable(void);

/* Disable Interrupt */
void SPI_voidInterruptDisable(void);

/* Enable SPI Circuit */
void SPI_voidEnable(void);

/* Disable SPI Circuit */
void SPI_voidDisable(void);

/* Transmit and Receive Data Between Master and SLave */
u8 SPI_u8TransmitReceive(u8 u8DataCpy);

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for SPI       */
/* Serial Transfer Complete                                    */
void SPI_voidCallBackSTC(PF PfFuncAddrCpy);

#endif