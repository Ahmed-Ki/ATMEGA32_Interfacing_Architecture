/************************************************/
/* Author      : Ahmed Khalid                   */
/* Description : Program file for STEPPER MOTOR */
/* Date        : 31 Aug 2019                    */
/* Version     : 1.0V                           */
/************************************************/


#include "STD_types.h"
#include "BIT_math.h"

//#include <util/delay.h>

#include "DIO_int.h"

#include "STEPPER_MOTOR_int.h"
#include "STEPPER_MOTOR_cfg.h"
#include "STEPPER_MOTOR_priv.h"


/* Function to initialize all Stepper Motors */


void STEPPERMOTOR_voidInit(void)
{
    u8 u8StepperMotorNbLoc;

    for(u8StepperMotorNbLoc = 0 ; u8StepperMotorNbLoc < STEPPER_MOTOR_MAX_NB ; u8StepperMotorNbLoc++)
    {
        STEPPERMOTOR_enuStop(u8StepperMotorNbLoc);
    }
}



/**********************************************/
/* Function to stop a specified Stepper Motor */
/* INPUT : u8MotorNBCpy ranges from           */
/*         0 to STEPPER_MOTOR_MAX_NB          */
/**********************************************/

ERRORSTATUS STEPPERMOTOR_enuStop(u8 u8MotorNbCpy)
{
    ERRORSTATUS enuErrorStatLoc = OK;

    if(u8MotorNbCpy >= STEPPER_MOTOR_MAX_NB)
    {
        enuErrorStatLoc = INDEX_OUT_OF_RANGE;
    }

    else
    {
        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW);
        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW);
        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW);
        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW);

    }

    return enuErrorStatLoc;
}


/*********************************************************************/
/* Function to turn a Stepper Motor in a specified direction         */
/* INPUTS :                                                          */
/*         u8MotorNbCpy: ranges from 0 to STEPPER_MOTOR_MAX_NB       */
/*         u8DirectionCpy : STEPPER_MOTOR_u8CW (ClockWise)           */
/*                          STEPPER_MOTOR_u8CCW (Counter ClockWise)  */
/*         u8StepperMotorMode :  STEPPERMOTOR_FULL_STEP_MODE         */
/*                               STEPPERMOTOR_HALF_STEP_MODE         */
/*********************************************************************/

ERRORSTATUS STEPPERMOTOR_enuMove(u8 u8MotorNbCpy , u8 u8DirectionCpy , u16 u16NbOfSteps, u8 u8StepperMotorMode)
{
    ERRORSTATUS enuErrorStatLoc = OK;

    u16 Loc_u16StepCtr;

    if(u8MotorNbCpy >= STEPPER_MOTOR_MAX_NB)
    {
        enuErrorStatLoc = INDEX_OUT_OF_RANGE;
    }

    else
    {
        if(u8StepperMotorMode == STEPPERMOTOR_FULL_STEP_MODE)
        {
            switch(u8DirectionCpy)
            {
                case STEPPER_MOTOR_u8CW:
                    for (Loc_u16StepCtr = 0;Loc_u16StepCtr < u16NbOfSteps; Loc_u16StepCtr++)
                    {
                        /* sequence 1  */
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
		    			_delay_ms(2);
    
		    			/* sequence 2  */
		    		    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
		    			_delay_ms(2);
    
		    			/* sequence 3  */
		                DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
		    			_delay_ms(2);
    
		    			/* sequence 4  */
                        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
		    			_delay_ms(2);

                    }
                break;


                case STEPPER_MOTOR_u8CCW:
                     for (Loc_u16StepCtr = 0;Loc_u16StepCtr < u16NbOfSteps; Loc_u16StepCtr++)
                    {
                        /* sequence 1  */
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
		    			_delay_ms(2);
    
		    			/* sequence 2  */
		    		    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
		    			_delay_ms(2);
    
		    			/* sequence 3  */
		                DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
		    			_delay_ms(2);
    
		    			/* sequence 4  */
                        DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
		    			DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
		    			_delay_ms(2);

                    }
                break;

                default: 
                    enuErrorStatLoc = NOK;

            }
        }
        else if(u8StepperMotorMode == STEPPERMOTOR_HALF_STEP_MODE)
        {
            switch(u8DirectionCpy)
            {
                case STEPPER_MOTOR_u8CW:
                for (Loc_u16StepCtr = 0;Loc_u16StepCtr < u16NbOfSteps; Loc_u16StepCtr++)
                {
                    /* sequence 1  */
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);
					
					/* sequence 2  */
				    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);
								
					/* sequence 3  */
		            DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);
								
					/* sequence 4  */
                    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);

                    /* sequence 5  */
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);
					
					/* sequence 6  */
				    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);
								
					/* sequence 7  */
		            DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);
								
					/* sequence 8  */
                    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);
                    
                }
            break;
            case STEPPER_MOTOR_u8CCW:
                for (Loc_u16StepCtr = 0;Loc_u16StepCtr < u16NbOfSteps; Loc_u16StepCtr++)
                {
                    /* sequence 1  */
                    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);

                    /* sequence 2  */
		            DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);

                    /* sequence 3  */
				    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8HIGH );
					_delay_ms(2);

                    /* sequence 4  */
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);

                    /* sequence 5  */
                    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);

                    			
					/* sequence 6  */
		            DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);

                    /* sequence 7  */
				    DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);

                     /* sequence 8  */
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8OrangeWire , DIO_u8HIGH );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8YellowWire , DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8PinkWire ,   DIO_u8LOW  );
					DIO_voidSetPinValue(astrStepperMotorPinCfg[u8MotorNbCpy].u8BlueWire ,   DIO_u8LOW  );
					_delay_ms(2);
                    
                }
            break;

            default: 
                enuErrorStatLoc = NOK;
                

            }
        }
        else
        {
            enuErrorStatLoc = NOK;
        }
    }
    return enuErrorStatLoc;
}            










