/***********************************************/
/* Author      : Ahmed Khalid                  */
/* Description : Configuration file for TIMER0 */
/* Date        : 15 Sep 2019                   */
/* Version     : 1.0V                          */
/***********************************************/

#ifndef TIMER0_CFG_H
#define TIMER0_CFG_H

/************************************/
/*      Waveform Generation Mode    */
/* Modes : NORMAL                   */
/*       : PWM_PHASE_CORRECT        */
/*       : CTC (NON_PWM)            */
/*       : FAST_PWM                 */
/************************************/
/* PWM : Pulse Width Modulation     */
/* CTC : Compare Match Output Mode  */
/************************************/

#define TIMER0_WAVEFORM_GENERATION_MODE NORMAL

/*****************************************************/
/*     Compare Match Output Mode for Non-PWM Mode    */
/* Modes : NORMAL_OP (OC0 disconnected)              */
/*       : TOGGLE_OC0_ON_COM                         */
/*       : CLEAR_OC0_ON_COM                          */
/*		 : SET_OC0_ON_COM                            */
/*****************************************************/

#define TIMER0_COM_NON_PWM NORMAL_OP

/******************************************************************/
/*          Compare Match Output Mode for Fast PWM Mode           */
/* Modes : NORMAL_OP (OC0 disconnected)                           */
/*       : CLEAR_OC0_ON_COM_SET_TOP (While setting OC0 at TOP)    */
/*		 : SET_OC0_ON_COM_CLEAR_TOP   (While Clearing OC0 at TOP) */
/******************************************************************/

#define TIMER0_COM_FAST_PWM NORMAL_OP

/*****************************************************************************/
/*           Compare Match Output Mode for Phase Correct PWM Mode            */
/* Modes : NORMAL_OP (OC0 disconnected)                                      */
/*       : CLEAR_OC0_ON_COM_UP_COUNTING (Set OC0 on COM when downcounting)   */
/*		 : SET_OC0_ON_COM_UP_COUNTING   (Clear OC0 on COM when downcounting) */
/*****************************************************************************/

#define TIMER0_COM_PHASE_CORRECT_PWM NORMAL_OP

/*********************************************/
/*              TIMER0 PRESCALAR             */
/* Modes :TIMER0_NO_CLOCK                    */
/*       :TIMER0_DIV_BY_1                    */
/*       :TIMER0_DIV_BY_8                    */
/*       :TIMER0_DIV_BY_64                   */
/*       :TIMER0_DIV_BY_256                  */
/*       :TIMER0_DIV_BY_1024                 */
/*       :TIMER0_EXTERNAL_CLOCK_FALLING_EDGE */
/*		 :TIMER0_EXTERNAL_CLOCK_RISING_EDGE  */
/*********************************************/

#define TIMER0_PRESCALER TIMER0_DIV_BY_1024

#endif