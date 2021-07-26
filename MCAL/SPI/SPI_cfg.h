/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for SPI */
/* Date        : 12 Oct 2019                */
/* Version     : 1.0V                       */
/********************************************/


#ifndef SPI_CFG_H
#define SPI_CFG_H


/*         SPI Mode       */
/* Available modes:       */
/*                 MASTER */
/*                 SLAVE  */

#define SPI_MODE MASTER

/*            Clock Polarity           */
/* Availabe modes:                     */
/*                IDLE_LOW             */
/*                IDLE_HIGH            */
/***************************************/
/* IDLE_LOW: Leading edge is rising,   */
/*  trailing edge is falling           */
/* IDLE_HIGH: Leading edge is falling, */
/* trailing edge is rising             */

#define SPI_CLOCK_POLARITY  IDLE_LOW

/*            Clock Phase           */
/* Availabe modes:                  */
/*                ZERO              */
/*                ONE               */
/************************************/
/* ZERO: sample at leading edge and */
/* setup at trailing edge           */
/* ONE: sample at trailing edge and */
/* setup at falling edge            */

#define SPI_CLOCK_PHASE     ZERO

/*              Clock Rate               */
/* Available clock rates:                */
/*                          FCPU_2       */
/*                          FCPU_4       */
/*                          FCPU_8       */
/*                          FCPU_16      */
/*                          FCPU_32      */
/*                          FCPU_64      */
/*                          FCPU_128     */
/*****************************************/
/* Note: FCPU_X divides FCPU by X        */

#define SPI_CLOCK_RATE  FCPU_4

/*          Data Order        */
/* Available modes:           */
/*                  LSB_FIRST */
/*                  MSB_FIRST */

#define SPI_DATA_ORDER  LSB_FIRST



#endif