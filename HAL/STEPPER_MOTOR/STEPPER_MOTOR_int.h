/**************************************************/
/* Author      : Ahmed Khalid                     */
/* Description : Interface file for STEPPER MOTOR */
/* Date        : 31 Aug 2019                      */
/* Version     : 1.0V                             */
/**************************************************/


#ifndef     STEPPER_MOTOR_INT_H
#define     STEPPER_MOTOR_INT_H

/* Macro to turn direction clockwise */
#define STEPPER_MOTOR_u8CW         1

/* Macro to turn direction counter clockwise */
#define STEPPER_MOTOR_u8CCW        2


#define STEPPERMOTOR_FULL_ROTATION_360_DEGREE	512
#define STEPPERMOTOR_HALF_ROTATION_180_DEGREE	256
#define STEPPERMOTOR_QUARTER_ROTATION_90_DEGREE	128

#define STEPPERMOTOR_FULL_STEP_MODE            55
#define STEPPERMOTOR_HALF_STEP_MODE            57

/* Function to initialize all Stepper Motors */

void STEPPERMOTOR_voidInit(void);

/**********************************************/
/* Function to stop a specified Stepper Motor */
/* INPUT : u8MotorNBCpy ranges from           */
/*         0 to STEPPER_MOTOR_MAX_NB          */
/**********************************************/

ERRORSTATUS STEPPERMOTOR_enuStop(u8 u8MotorNbCpy);

/*********************************************************************/
/* Function to turn a Stepper Motor in a specified direction         */
/* INPUTS :                                                          */
/*         u8MotorNbCpy: ranges from 0 to STEPPER_MOTOR_MAX_NB       */
/*         u8DirectionCpy : STEPPER_MOTOR_u8CW (ClockWise)           */
/*                          STEPPER_MOTOR_u8CCW (Counter ClockWise)  */
/*         u8StepperMotorMode :  STEPPERMOTOR_FULL_STEP_MODE         */
/*                               STEPPERMOTOR_HALF_STEP_MODE         */
/*********************************************************************/

ERRORSTATUS STEPPERMOTOR_enuMove(u8 u8MotorNbCpy , u8 u8DirectionCpy , u16 u16NbOfSteps, u8 u8StepperMotorMode);


 



#endif