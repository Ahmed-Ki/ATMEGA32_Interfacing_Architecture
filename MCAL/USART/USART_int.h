/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for USART */
/* Date        : 17 Oct 2019            */
/* version     : 1.0V                   */
/****************************************/

#ifndef USART_INT_H
#define USART_INT_H

/* Initialize USART */
void USART_voidInit(void);

/* Enable Transmitter Circuit */
void USART_voidEnableTransmitter(void);

/* Disable Transmitter Circuit */
void USART_voidDisableTransmitter(void);

/* Enable Receiver Circuit */
void USART_voidEnableReceiver(void);

/* Disable Receiver Circuit */
void USART_voidDisableReceiver(void);

/* Enable Data Register Empty Interrupt */
void USART_voidDataRegisterEmptyInterruptEnable(void);

/* Disable Data Register Empty Interrupt */
void USART_voidDataRegisterEmptyInterruptDisable(void);

/* Enable Transmission Complete Interrupt */
void USART_voidTransmissionCompleteInterruptEnable(void);

/* Disable Transmission Complete Interrupt */
void USART_voidTransmissionCompleteInterruptDisable(void);

/* Enable Transmission Complete Interrupt */
void USART_voidReceiveCompleteInterruptEnable(void);

/* Disable Transmission Complete Interrupt */
void USART_voidReceiveCompleteInterruptDisable(void);

/* Transmit 8bit Data */
void USART_voidTransmit(u8 u8Data);

/* Receive 8bit Data */
u8 USART_u8Receive(void);

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Receive Complete                                            */
void USART_voidCallBackRXC(PF PfFuncAddrCpy);


/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Data Register Empty                                         */
void USART_voidCallBackUDRE(PF PfFuncAddrCpy);



/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Transmission Complete                                       */
void USART_voidCallBackTXC(PF PfFuncAddrCpy);



#endif