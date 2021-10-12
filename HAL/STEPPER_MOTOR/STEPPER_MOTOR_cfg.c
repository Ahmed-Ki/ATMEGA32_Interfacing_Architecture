/********************************************************/
/* Author      : Ahmed Khalid                           */
/* Description : Configuration.c file for STEPPER MOTOR */
/* Date        : 31 Aug 2019                            */
/* Version     : 1.0V                                   */
/********************************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"


#include "STEPPER_MOTOR_cfg.h"
#include "STEPPER_MOTOR_priv.h"



/* Mapping MicroCtroller PINS to Stepper Motors */

tstrStepperMotorPins astrStepperMotorPinCfg[STEPPER_MOTOR_MAX_NB] =
{
    {DIO_PIN_0,DIO_PIN_1,DIO_PIN_2,DIO_PIN_3},
    {DIO_PIN_4,DIO_PIN_5,DIO_PIN_6,DIO_PIN_7}
};






