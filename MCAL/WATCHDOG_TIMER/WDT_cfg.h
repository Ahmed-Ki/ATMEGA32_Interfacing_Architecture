/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for WDT */
/* Date        : 5 Oct 2019                 */
/* version     : 1.0V                       */
/********************************************/


#ifndef WDT_CFG_H
#define WDT_CFG_H


/*************************************/
/*        WATCHDOG PRESCALER         */
/* Modes:TIME_OUT_16_3_MS            */
/*      :TIME_OUT_32_5_MS            */
/*      :TIME_OUT_65_MS              */
/*      :TIME_OUT_0_13_S             */
/*      :TIME_OUT_0_26_S             */
/*      :TIME_OUT_0_52_S             */
/*      :TIME_OUT_1_S                */
/*		:TIME_OUT_2_1_S              */
/*************************************/
/* Each _ after a number corresponds */
/* to a decimal point                */
/*************************************/

#define WDT_TIME_OUT TIME_OUT_2_1_S

#endif