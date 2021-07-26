/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for USART */
/* Date        : 11 Oct 2019            */
/* Version     : 1.0V                   */
/****************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "USART_int.h"
#include "USART_cfg.h"
#include "USART_priv.h"

PF USART_PfCallBackAddrRXC = NULL;

PF USART_PfCallBackAddrUDRE = NULL;

PF USART_PfCallBackAddrTXC = NULL;

void SET_u8UCSRCBit(u8 u8Reg, u8 u8Bit)
{
	u8 Loc_u8TempReg = 0;
	Loc_u8TempReg = UCSRC;
	SET_BIT(u8Reg, u8Bit);
}

void CLEAR_u8UCSRCBit(u8 u8Reg, u8 u8Bit)
{
	u8 Loc_u8TempReg = 0;
	Loc_u8TempReg = UCSRC;
	CLEAR_BIT(u8Reg, u8Bit);
}

void GET_u8UCSRCBit(u8 u8Reg, u8 u8Bit)
{
	u8 Loc_u8TempReg = 0;
	Loc_u8TempReg = UCSRC;
	GET_BIT(u8Reg, u8Bit);
}

/* Initialize USART */
void USART_voidInit(void)
{

	u16 Loc_u16UBBR_Value = 0;

	/* SET URSEL to enable writing in UCSRC */
	SET_u8UCSRCBit(UCSRC, 7);

#if USART_OPERATION_MODE == ASYNCHRONOUS
	CLEAR_u8UCSRCBit(UCSRC, 6);

#elif USART_OPERATION_MODE == SYNCHRONOUS
	SET_u8UCSRCBit(UCSRC, 6);

#else
	CLEAR_u8UCSRCBit(UCSRC, 6);

#endif

/* Parity */
#if USART_PARITY_MODE == DISABLED
	CLEAR_u8UCSRCBit(UCSRC, 4);
	CLEAR_u8UCSRCBit(UCSRC, 5);

#elif USART_PARITY_MODE == EVEN
	CLEAR_u8UCSRCBit(UCSRC, 4);
	SET_u8UCSRCBit(UCSRC, 5);

#elif USART_PARITY_MODE == ODD
	SET_u8UCSRCBit(UCSRC, 4);
	SET_u8UCSRCBit(UCSRC, 5);

#else
	CLEAR_u8UCSRCBit(UCSRC, 4);
	CLEAR_u8UCSRCBit(UCSRC, 5);

#endif

/* Speed Mode */
#if USART_OPERATION_MODE == ASYNCHRONOUS

#if USART_SPEED_OPERATION == DOUBLE_SPEED_MODE
	SET_BIT(UCSRA, 1);

#elif USART_SPEED_OPERATION == NORMAL_SPEED_MODE
	CLEAR_BIT(UCSRA, 1);
#endif

#elif USART_OPERATION_MODE == SYNCHRONOUS
	CLEAR_BIT(UCSRA, 1);

#endif

/*  UBBR Value Equation	*/
#if USART_OPERATION_MODE == ASYNCHRONOUS
#if USART_SPEED_OPERATION == NORMAL_SPEED_MODE
	/* Asynchronous Normal Mode 			*/
	Loc_u16UBBR_Value = ((F_CPU / (16 * USART_BAUD_RATE)) - 1);

#elif USART_SPEED_OPERATION == DOUBLE_SPEED_MODE
	/* Asynchronous Double Speed Mode 		*/
	Loc_u16UBBR_Value = ((F_CPU / (8 * USART_BAUD_RATE)) - 1);
#endif
#elif USART_OPERATION_MODE == SYNCHRONOUS
	/* Synchronous Master Mode				*/
	Loc_u16UBBR_Value = ((F_CPU / (2 * USART_BAUD_RATE)) - 1);

#endif
	/* CLEAR URSEL to enable writing in UBBRH */
	CLEAR_u8UCSRCBit(UCSRC, 7);

	/* Set baud rate */
	UBRRH = (u8)(Loc_u16UBBR_Value >> 8);
	UBRRL = (u8)Loc_u16UBBR_Value;

	/* SET URSEL to enable writing in UCSRC */
	SET_u8UCSRCBit(UCSRC, 7);

	/* Enable receiver and transmitter */
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

/*	 Character Size N-Bits */
#if USART_FRAME_SIZE == 5
	CLEAR_u8UCSRCBit(UCSRC, 1);
	CLEAR_u8UCSRCBit(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);

#elif USART_FRAME_SIZE == 6
	SET_u8UCSRCBit(UCSRC, 1);
	CLEAR_u8UCSRCBit(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);

#elif USART_FRAME_SIZE == 7
	CLEAR_u8UCSRCBit(UCSRC, 1);
	SET_u8UCSRCBit(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);

#elif USART_FRAME_SIZE == 8
	SET_u8UCSRCBit(UCSRC, 1);
	SET_u8UCSRCBit(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);

#elif USART_FRAME_SIZE == 9
	SET_u8UCSRCBit(UCSRC, 1);
	SET_u8UCSRCBit(UCSRC, 2);
	SET_BIT(UCSRB, 2);

#endif

/*	Stop bit select number One or Two Bits */
#if USART_STOP_BIT_SELECT == TWO_BIT
	SET_u8UCSRCBit(UCSRC, 3);

#elif USART_STOP_BIT_SELECT == ONE_BIT
	CLEAR_u8UCSRCBit(UCSRC, 3);

#endif

/*  Clock polarity	*/
#if USART_OPERATION_MODE == SYNCHRONOUS

#if CLOCK_POLARITY == RISING
	CLEAR_u8UCSRCBit(UCSRC, 0);

#elif CLOCK_POLARITY == FALLING
	SET_u8UCSRCBit(UCSRC, 0);

#endif

#endif
}

/* Enable Transmitter Circuit */
void USART_voidEnableTransmitter(void)
{
	SET_BIT(UCSRB, 3);
}

/* Disable Transmitter Circuit */
void USART_voidDisableTransmitter(void)
{
	CLEAR_BIT(UCSRB, 3);
}

/* Enable Receiver Circuit */
void USART_voidEnableReceiver(void)
{
	SET_BIT(UCSRB, 4);
}

/* Disable Receiver Circuit */
void USART_voidDisableReceiver(void)
{
	CLEAR_BIT(UCSRB, 4);
}

/* Enable Data Register Empty Interrupt */
void USART_voidDataRegisterEmptyInterruptEnable(void)
{
	SET_BIT(UCSRB, 5);
}

/* Disable Data Register Empty Interrupt */
void USART_voidDataRegisterEmptyInterruptDisable(void)
{
	CLEAR_BIT(UCSRB, 5);
}

/* Enable Transmission Complete Interrupt */
void USART_voidTransmissionCompleteInterruptEnable(void)
{
	SET_BIT(UCSRB, 6);
}

/* Disable Transmission Complete Interrupt */
void USART_voidTransmissionCompleteInterruptDisable(void)
{
	CLEAR_BIT(UCSRB, 6);
}

/* Enable Transmission Complete Interrupt */
void USART_voidReceiveCompleteInterruptEnable(void)
{
	SET_BIT(UCSRB, 7);
}

/* Disable Transmission Complete Interrupt */
void USART_voidReceiveCompleteInterruptDisable(void)
{
	CLEAR_BIT(UCSRB, 7);
}
/* Transmit 8bit Data */
void USART_voidTransmit(u8 u8Data)
{
	while (GET_BIT(UCSRA, 5) == 0)
		;

	UDR = u8Data;
}

/* Receive 8bit Data */
u8 USART_u8Receive(void)
{
	while (GET_BIT(UCSRA, 7) == 0)
		;

	return UDR;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Receive Complete                                            */
void USART_voidCallBackRXC(PF PfFuncAddrCpy)
{
	USART_PfCallBackAddrRXC = PfFuncAddrCpy;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Data Register Empty                                         */
void USART_voidCallBackUDRE(PF PfFuncAddrCpy)
{
	USART_PfCallBackAddrUDRE = PfFuncAddrCpy;
}

/* This is a CallBack function used in the Application layer   */
/* to write your ISR (Interrupt Service Routine) for USART     */
/* Transmission Complete                                       */
void USART_voidCallBackTXC(PF PfFuncAddrCpy)
{
	USART_PfCallBackAddrTXC = PfFuncAddrCpy;
}

void __vector_13(void) __attribute__((signal, used));
void __vector_13(void)
{
	if (USART_PfCallBackAddrRXC != NULL)
	{
		USART_PfCallBackAddrRXC();
	}
}

void __vector_14(void) __attribute__((signal, used));
void __vector_14(void)
{
	if (USART_PfCallBackAddrUDRE != NULL)
	{
		USART_PfCallBackAddrUDRE();
	}
}

void __vector_15(void) __attribute__((signal, used));
void __vector_15(void)
{
	if (USART_PfCallBackAddrTXC != NULL)
	{
		USART_PfCallBackAddrTXC();
	}
}
