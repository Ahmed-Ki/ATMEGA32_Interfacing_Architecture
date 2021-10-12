/*****************************************/
/* Author      : Ahmed Khalid            */
/* Description : Interface file for SRTO */
/* Date        : 1 Nov 2019              */
/* Version     : 1.0V                    */
/*****************************************/

#ifndef SRTO_INT_H
#define SRTO_INT_H

typedef enum state
{
    RUN,
    WAIT
} tenuStatus;

typedef struct
{

    u16 u16Periodicity;

    u16 u16FirstDelay;

    tenuStatus Status;

    PF PfTaskFunction;

} tstrTASK;

void SRTO_voidInit(void);

ERRORSTATUS SRTO_enuPlayTask(u16 u16PriorityCpy);

ERRORSTATUS SRTO_enuPauseTask(u16 u16PriorityCpy);

ERRORSTATUS SRTO_enuDeleteTask(u16 u16PriorityCpy);

ERRORSTATUS SRTO_enuCreateTask(u16 u16PriorityCpy, tstrTASK *pstrTaskCpy);

#endif