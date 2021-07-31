/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for I2C */
/* Date        : 18 Oct 2019                */
/* Version     : 1.0V                       */
/********************************************/


#ifndef I2C_CFG_H
#define I2C_CFG_H



/* TWI General Call */
/* Modes:           */
/*        ENABLED   */
/*        DISABLED  */


#define TWI_GENERAL_CALL    DISABLED

/*               Prescaler Bits               */
/* Available Values:                          */
/*                    1                       */
/*                    4                       */
/*                    16                      */
/*                    64                      */
/**********************************************/
/* Note: SCL Frequency is determined by:      */
/* SCL Frequency =          F_CPU             */
/*                 ----------------------     */
/*                 16 + 2*(TWBR)*(4^TWPS)     */
/**********************************************/
/* TWBR = Value of TWI Bite Rate Register     */
/* Max Value of TWBR = 255 but cannot be < 10 */
/**********************************************/
/* TWPS = Value of Prescaler Bits             */
/**********************************************/
/* F_CPU = 8000000                            */

#define TWI_PRESCALER 4

#define TWI_TWBR_VALUE  10

#endif