/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Interface file for EEPROM */
/* Date        : 19 Oct 2019               */
/* Version     : 1.0V                      */
/*******************************************/

#ifndef EEPROM_INT_H
#define EEPROM_INT_H

/* Initialize EEPROM */
void EEPROM_voidInit(void);

/* Write a Byte to EEPROM */
ERRORSTATUS EEPROM_enuWriteByte(u16 u16LocationCpy, u8 u8DataCpy);

/* Read a Byte from EEPROM */
u8 EEPROM_u8ReadByte(u16 u16LocationCpy);

#endif