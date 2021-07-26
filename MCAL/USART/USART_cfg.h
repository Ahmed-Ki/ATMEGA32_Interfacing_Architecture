/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Private file for USART */
/* Date        : 11 Oct 2019            */
/* Version     : 1.0V                   */
/****************************************/

#ifndef USART_CFG_H
#define USART_CFG_H

/*        Mode of operation     */
/* Available modes:             */
/*                 ASYNCHRONOUS */
/*                 SYNCHRONOUS  */

#define USART_OPERATION_MODE    ASYNCHRONOUS

/* Speed operation is only available  */
/* in Asynchronous mode only          */
/* Available speeds:                  */
/*                  NORMAL_SPEED_MODE */
/*                  DOUBLE_SPEED_MODE */

#define USART_SPEED_OPERATION   NORMAL_SPEED_MODE

/* Data bits in a frame */
/* Available size:      */
/*                5     */
/*                6     */
/*                7     */
/*                8     */
/*                9     */

#define USART_FRAME_SIZE    8


/*         Parity Modes      */
/* Available parity:         */
/*                  DISABLED */
/*                  EVEN     */
/*                  ODD      */

#define USART_PARITY_MODE   DISABLED


/*        Stop Bit Select       */
/* Available stop bits:         */
/*                     ONE_BIT  */
/*                     TWO_BITS */

#define USART_STOP_BIT_SELECT   TWO_BITS

/*                        Clock Polarity                        */
/****************************************************************/
/*	UCPOL = 0 Rising Edge (Transmitted) Falling Edge (Received)	*/
/*	UCPOL = 1 Falling Edge (Transmitted) Rising Edge (Received) */ 
/****************************************************************/
/* Available clock polarity:                                    */
/*					    	RISING			 		            */
/*						    FALLING					            */
/****************************************************************/

#define USART_CLOCK_POLARITY		RISING



/* CPU Frequency */
#define F_CPU   8000000




/*              Baud Rate Select                */
/* For Asynchronous mode only                   */
/* Note: Currently using Cpu frequency = 8MHz   */
/* Availabe baud rate for F_CPU = 8MHz:         */
/*                                     2400     */
/*                                     4800     */
/*                                     9600     */
/*                                     14.4k    */
/*                                     19.2k    */
/*                                     28.8k    */
/*                                     38.4k    */
/*                                     57.6k    */
/*                                     76.8k    */
/*                                     115.2k   */
/*                                     230.4k   */
/*                                     250k     */
/*                                     0.5M     */
/*                                     1M       */
/************************************************/
/* Note: 1M only works with DOUBLE_SPEED_MODE   */
/************************************************/

#define USART_BAUD_RATE     9600

#endif
