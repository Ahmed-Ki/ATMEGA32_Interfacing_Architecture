/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for DIO */
/* Date        : 17 Aug 2019          */
/* Version     : 1.0v                 */
/**************************************/

#ifndef DIO_PRIV_H
#define DIO_PRIV_H

/**************************************/
/* Description: INPUT and OUT value   */
/*              definitions           */
/**************************************/

#define DIO_u8INPUT			0
#define DIO_u8OUTPUT		1
				
/***************************************************/
/* Description :  MEMEROY MAPPING I/O  Peripheral  */
/***************************************************/

/*          REGISTER ADDRESSES FOR PORT A          */
#define PORTA      *((volatile u8 *) 0x3B)
#define DDRA       *((volatile u8 *) 0x3A)
#define PINA       *((volatile u8 *) 0x39)

/*          REGISTER ADDRESSES FOR PORT B          */
#define PORTB      *((volatile u8 *) 0x38)
#define DDRB       *((volatile u8 *) 0x37)
#define PINB       *((volatile u8 *) 0x36)

/*          REGISTER ADDRESSES FOR PORT C          */
#define PORTC      *((volatile u8 *) 0x35)
#define DDRC       *((volatile u8 *) 0x34)
#define PINC       *((volatile u8 *) 0x33)
        
/*          REGISTER ADDRESSES FOR PORT D          */
#define PORTD      *((volatile u8 *) 0x32)
#define DDRD       *((volatile u8 *) 0x31)
#define PIND       *((volatile u8 *) 0x30)



#endif





//prototypes of private functions
//registers of the driver