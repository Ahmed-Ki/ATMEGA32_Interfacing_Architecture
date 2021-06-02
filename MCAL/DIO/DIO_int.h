/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for DIO */
/* Date        : 17 Aug 2019            */
/* Version     : 1.0v                   */
/****************************************/

#ifndef DIO_INT_H
#define DIO_INT_H


/*************************************/
/* Description: Definitions of       */
/*              HIGH and LOW values  */
/*************************************/

#define DIO_u8HIGH    1
#define DIO_u8LOW     0

/*************************************/
/* Description : PIN Definitions     */
/*               PORT A PINS         */

#define DIO_PIN_0           0
#define DIO_PIN_1           1
#define DIO_PIN_2           2
#define DIO_PIN_3           3
#define DIO_PIN_4           4
#define DIO_PIN_5           5
#define DIO_PIN_6           6
#define DIO_PIN_7           7

/*               PORT B PINS          */

#define DIO_PIN_8           8
#define DIO_PIN_9           9
#define DIO_PIN_10          10
#define DIO_PIN_11          11
#define DIO_PIN_12          12
#define DIO_PIN_13          13
#define DIO_PIN_14          14
#define DIO_PIN_15          15

/*               PORT C PINS           */

#define DIO_PIN_16         16
#define DIO_PIN_17         17
#define DIO_PIN_18         18
#define DIO_PIN_19         19
#define DIO_PIN_20         20
#define DIO_PIN_21         21
#define DIO_PIN_22         22
#define DIO_PIN_23         23

/*               PORT D PINS            */

#define DIO_PIN_24         24
#define DIO_PIN_25         25
#define DIO_PIN_26         26
#define DIO_PIN_27         27
#define DIO_PIN_28         28
#define DIO_PIN_29         29
#define DIO_PIN_30         30
#define DIO_PIN_31         31



/*********************************************/
/* Description : Initialization function     */
/*               it intializes the direction */
/*               of the PINS based on the    */
/*               cfg file                    */   
/*********************************************/

void DIO_voidInit(void);


/**********************************************/
/* Description: This function sets the PINs   */  
/*              value to HIGH or LOW          */       
/* INPUTS :                                   */
/*          u8PinNbCpy  : DIO_PIN_x           */
/*                      x in Range [0 .. 31]  */
/*          u8PinValueCpy : DIO_u8HIGH        */
/*                         DIO_u8LOW          */
/**********************************************/

void DIO_voidSetPinValue(u8 u8PinNbCpy , u8 u8PinValueCpy);



/*********************************************/
/* Description: This function reads the      */
/*              PIN value                    */     
/* INPUT :                                   */
/*          u8PinNbCpy  : DIO_PIN_x          */
/*                      x in Range [0 .. 31] */
/*********************************************/

u8 DIO_u8GetPinValue(u8 u8PinNbCpy);


/*********************************************/
/* Description: This function toggles the     */
/*              value of the PIN             */
/*********************************************/

void DIO_voidTogglePinValue(u8 u8PinNbCpy);


/*********************************************/
/* Description: This function changes the    */
/*              PIN direction in Run time    */
/*********************************************/

void DIO_voidSetPinDirectionRunTime(u8 u8PinNbCpy, u8 u8PinDirectionCpy);




#endif


//prototypes functions and extern of global variables
//prototypes of public functions


