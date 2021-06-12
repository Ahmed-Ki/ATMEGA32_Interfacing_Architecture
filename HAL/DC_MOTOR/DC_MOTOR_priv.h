/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Private file for DC MOTOR */
/* Date        : 31 Aug 2019               */
/* Version     : 1.0V                      */
/*******************************************/



#ifndef     DC_MOTOR_PRIV_H
#define     DC_MOTOR_PRIV_H


/* Macro to turn direction clockwise */
#define DC_MOTOR_u8CW         1

/* Macro to turn direction counter clockwise */
#define DC_MOTOR_u8CCW        2

/* Struct to define DC Motor Pins */
typedef struct 
{
    u8 u8PIN_0;
    u8 u8PIN_1;

}tstrDcMotorPins;

extern tstrDcMotorPins astrDcMotorPinCfg[DC_MOTOR_MAX_NB];



#endif