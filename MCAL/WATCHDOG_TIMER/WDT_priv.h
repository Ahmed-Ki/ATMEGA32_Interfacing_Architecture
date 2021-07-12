/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for WDT */
/* Date        : 5 Oct 2019           */
/* version     : 1.0V                 */
/**************************************/



#ifndef WDT_PRIV_H
#define WDT_PRIV_H


#define TIME_OUT_16_3_MS    1
#define TIME_OUT_32_5_MS    3
#define TIME_OUT_65_MS      5
#define TIME_OUT_0_13_S     7
#define TIME_OUT_0_26_S     9
#define TIME_OUT_0_52_S     11
#define TIME_OUT_1_S        13
#define TIME_OUT_2_1_S      15


/* Memory mapped address of Watchdog Timer Control Register (WDTCR) */
#define WDTCR		*((volatile u8 *)   0x41)

#endif

















