/***************************************************/
/* Author      : Ahmed Khalid                      */
/* Description : Configuration.c file for DC MOTOR */
/* Date        : 31 Aug 2019                       */
/* Version     : 1.0V                              */
/***************************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"


#include "DC_MOTOR_cfg.h"
#include "DC_MOTOR_priv.h"



/* Mapping MicroCtroller PINS to DC Motors */

tstrDcMotorPins astrDcMotorPinCfg[DC_MOTOR_MAX_NB] =
{
    {DIO_PIN_0,DIO_PIN_1},
    {DIO_PIN_2,DIO_PIN_3}
};






