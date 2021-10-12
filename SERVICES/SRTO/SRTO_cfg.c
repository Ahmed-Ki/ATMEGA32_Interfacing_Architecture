/***********************************************/
/* Author      : Ahmed Khalid                  */
/* Description : Configuration.c file for SRTO */
/* Date        : 1 Nov 2019                    */
/* Version     : 1.0V                          */
/***********************************************/



#include "SRTO_int.h"
#include "SRTO_cfg.h"

//#include "APP.h"


tstrTASK astrTask[TASK_NB]={
	{2000,0   , RUN , LED_ON  },
	{2000,1000, RUN , LED_OFF }
	
	
};