/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for WDT */
/* Date        : 5 Oct 2019           */
/* version     : 1.0V                 */
/**************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "WDT_int.h"
#include "WDT_cfg.h"
#include "WDT_priv.h"

/* Enable Watchdog Timer and sets */
/* watchdog time-out based on     */
/* configuration choice in cfg    */
void WDT_voidEnable(void)
{
#if WDT_TIME_OUT == TIME_OUT_16_3_MS
	CLEAR_BIT(WDTCR, 0);
	CLEAR_BIT(WDTCR, 1);
	CLEAR_BIT(WDTCR, 2);
#elif WDT_TIME_OUT == TIME_OUT_32_5_MS
	SET_BIT(WDTCR, 0);
	CLEAR_BIT(WDTCR, 1);
	CLEAR_BIT(WDTCR, 2);
#elif WDT_TIME_OUT == TIME_OUT_65_MS
	CLEAR_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	CLEAR_BIT(WDTCR, 2);
#elif WDT_TIME_OUT == TIME_OUT_0_13_S
	SET_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	CLEAR_BIT(WDTCR, 2);
#elif WDT_TIME_OUT == TIME_OUT_0_26_S
	CLEAR_BIT(WDTCR, 0);
	CLEAR_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);

#elif WDT_TIME_OUT == TIME_OUT_0_52_S
	SET_BIT(WDTCR, 0);
	CLEAR_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);
#elif WDT_TIME_OUT == TIME_OUT_1_S
	CLEAR_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);

#elif WDT_TIME_OUT == TIME_OUT_2_1_S
	SET_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);

/* Default Time-out 16.3ms */
#else
	CLEAR_BIT(WDTCR, 0);
	CLEAR_BIT(WDTCR, 1);
	CLEAR_BIT(WDTCR, 2);
#endif

	/* Enable WatchDog Timer */
	WDTCR |= (1 << 3);
}

/* Disable Watchdog Timer */
void WDT_voidDisable(void)
{
	WDTCR |= ((1 << 3) | (1 << 4));

	WDTCR = 0x00;
}

/* Refresh Watchdog Timer */
void WDT_voidRefresh(void)
{
	asm("WDR");
}
