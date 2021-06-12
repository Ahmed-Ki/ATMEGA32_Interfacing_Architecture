/*********************************************/
/* Author      : Ahmed Khalid                */
/* Description : Interface file for DC MOTOR */
/* Date        : 31 Aug 2019                 */
/* Version     : 1.0V                        */
/*********************************************/


#ifndef     DC_MOTOR_INT_H
#define     DC_MOTOR_INT_H

/* Macro to turn direction clockwise */
#define DC_MOTOR_u8CW         1

/* Macro to turn direction counter clockwise */
#define DC_MOTOR_u8CCW        2

/* Function to initialize all DC Motors */

void DCMOTOR_voidInit(void);

/*****************************************/
/* Function to stop a specified DC Motor */
/* INPUT : u8MotorNBCpy ranges from      */
/*         0 to DC_MOTOR_MAX_NB          */
/*****************************************/

ERRORSTATUS DCMOTOR_enuStop(u8 u8MotorNbCpy);

/****************************************************************/
/* Function to turn a DC Motor in a specified direction         */
/* INPUTS :                                                     */
/*         u8MotorNbCpy: ranges from 0 to DC_MOTOR_MAX_NB       */
/*         u8DirectionCpy : DC_MOTOR_u8CW (ClockWise)           */
/*                          DC_MOTOR_u8CCW (Counter ClockWise)  */
/****************************************************************/

ERRORSTATUS DCMOTOR_enuMove(u8 u8MotorNbCpy , u8 u8DirectionCpy);


 



#endif