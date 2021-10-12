/***********************************************/
/* Author      : Ahmed Khalid                  */
/* Description : Configuration file for TIMER2 */
/* Date        : 3 Oct 2021                    */
/* Version     : 1.0V                          */
/***********************************************/

#ifndef TIMER2_CFG_H
#define TIMER2_CFG_H

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

#define TIMER2_WAVEFORM_GENERATION_MODE NORMAL

/*****************************************************/
/*     Compare Match Output Mode for Non-PWM Mode    */
/* Modes : NORMAL_OP (OC2 disconnected)              */
/*       : TOGGLE_OC2_ON_COM                         */
/*       : CLEAR_OC2_ON_COM                          */
/*		 : SET_OC2_ON_COM                            */
/*****************************************************/

#define TIMER2_COM_NON_PWM NORMAL_OP

/******************************************************************/
/*          Compare Match Output Mode for Fast PWM Mode           */
/* Modes : NORMAL_OP (OC2 disconnected)                           */
/*       : CLEAR_OC2_ON_COM_SET_TOP (While setting OC2 at TOP)    */
/*		 : SET_OC2_ON_COM_CLEAR_TOP   (While Clearing OC2 at TOP) */
/******************************************************************/

#define TIMER2_COM_FAST_PWM NORMAL_OP

/*****************************************************************************/
/*           Compare Match Output Mode for Phase Correct PWM Mode            */
/* Modes : NORMAL_OP (OC2 disconnected)                                      */
/*       : CLEAR_OC2_ON_COM_UP_COUNTING (Set OC2 on COM when downcounting)   */
/*		 : SET_OC2_ON_COM_UP_COUNTING   (Clear OC2 on COM when downcounting) */
/*****************************************************************************/

#define TIMER2_COM_PHASE_CORRECT_PWM NORMAL_OP

/*********************************************/
/*              TIMER2 PRESCALAR             */
/* Modes :TIMER2_NO_CLOCK                    */
/*       :TIMER2_DIV_BY_1                    */
/*       :TIMER2_DIV_BY_8                    */
/*       :TIMER2_DIV_BY_32                   */
/*       :TIMER2_DIV_BY_64                   */
/*       :TIMER2_DIV_BY_128                  */
/*       :TIMER2_DIV_BY_256                  */
/*       :TIMER2_DIV_BY_1024                 */
/*********************************************/

#define TIMER2_PRESCALER TIMER2_DIV_BY_1024

#endif