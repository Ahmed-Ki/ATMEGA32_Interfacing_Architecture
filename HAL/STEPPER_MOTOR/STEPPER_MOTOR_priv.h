/************************************************/
/* Author      : Ahmed Khalid                   */
/* Description : Private file for STEPPER MOTOR */
/* Date        : 31 Aug 2019                    */
/* Version     : 1.0V                           */
/************************************************/



#ifndef     STEPPER_MOTOR_PRIV_H
#define     STEPPER_MOTOR_PRIV_H


/* Macro to turn direction clockwise */
#define STEPPER_MOTOR_u8CW         1

/* Macro to turn direction counter clockwise */
#define STERPPER_MOTOR_u8CCW       2

/* Struct to define Stepper Motor Pins */
typedef struct 
{
    u8 u8OrangeWire ;
    u8 u8YellowWire ;
    u8 u8PinkWire   ;    
    u8 u8BlueWire   ;

}tstrStepperMotorPins;

extern tstrStepperMotorPins astrStepperMotorPinCfg[STEPPER_MOTOR_MAX_NB];


#endif