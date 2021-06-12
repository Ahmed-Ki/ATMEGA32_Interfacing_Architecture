/*******************************************/
/* Author      : Ahmed Khalid              */
/* Description : Program file for DC MOTOR */
/* Date        : 31 Aug 2019               */
/* Version     : 1.0V                      */
/*******************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "DC_MOTOR_int.h"
#include "DC_MOTOR_cfg.h"
#include "DC_MOTOR_priv.h"

/* Function to initialize all DC Motors */

void DCMOTOR_voidInit(void)
{
    u8 u8DcMotorNbLoc;

    for(u8DcMotorNbLoc=0 ; u8DcMotorNbLoc < DC_MOTOR_MAX_NB ; u8DcMotorNbLoc++)
    {
        DCMOTOR_enuStop(u8DcMotorNbLoc);
    }

}

/*****************************************/
/* Function to stop a specified DC Motor */
/* INPUT : u8MotorNBCpy ranges from      */
/*         0 to DC_MOTOR_MAX_NB          */
/*****************************************/

ERRORSTATUS DCMOTOR_enuStop(u8 u8MotorNbCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;

    /* Check the index of the DC Motor */

    if(u8MotorNbCpy >= DC_MOTOR_MAX_NB)
    {
        enuErrorStatLoc = INDEX_OUT_OF_RANGE;
    }

    else
    {
        DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_0 , DIO_u8LOW);            
        DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_1 , DIO_u8LOW);        
    }

    return enuErrorStatLoc;
}


/****************************************************************/
/* Function to turn a DC Motor in a specified direction         */
/* INPUTS :                                                     */
/*         u8MotorNbCpy: ranges from 0 to DC_MOTOR_MAX_NB       */
/*         u8DirectionCpy : DC_MOTOR_u8CW (ClockWise)           */
/*                          DC_MOTOR_u8CCW (Counter ClockWise)  */
/****************************************************************/

ERRORSTATUS DCMOTOR_enuMove(u8 u8MotorNbCpy , u8 u8DirectionCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;

    /* Check the index of the DC Motor */

    if(u8MotorNbCpy >= DC_MOTOR_MAX_NB)
    {
        enuErrorStatLoc = INDEX_OUT_OF_RANGE;
    }

    else
    {
        switch(u8DirectionCpy)
        {
            /* Turn DC Motor ClockWise */
            case DC_MOTOR_u8CW:
                DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_0 ,DIO_u8HIGH );
                DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_1 ,DIO_u8LOW  );
                break;

            /* Turn DC Motor Counter ClockWise */
            case DC_MOTOR_u8CCW:
                DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_0 ,DIO_u8LOW  );
                DIO_voidSetPinValue(astrDcMotorPinCfg[u8MotorNbCpy].u8PIN_1 ,DIO_u8HIGH );
                break;

            default:
                enuErrorStatLoc = NOK;
                
        }
    }
    
    return enuErrorStatLoc;
}






