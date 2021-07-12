/****************************************/
/* Author      : Ahmed Khalid           */
/* Description : Interface file for WDT */
/* Date        : 5 Oct 2019             */
/* version     : 1.0V                   */
/****************************************/


#ifndef WDT_INT_H
#define WDT_INT_H



/* Enable Watchdog Timer and sets */
/* watchdog time-out based on     */
/* configuration choice in cfg    */
void WDT_voidEnable(void);

/* Disable Watchdog Timer */
void WDT_voidDisable(void);

/* Refresh Watchdog Timer */
void WDT_voidRefresh(void);


#endif














