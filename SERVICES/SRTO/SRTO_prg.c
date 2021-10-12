/***************************************/
/* Author      : Ahmed Khalid          */
/* Description : Program file for SRTO */
/* Date        : 1 Nov 2019            */
/* Version     : 1.0V                  */
/***************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "TIMER0_int.h"

#include "SRTO_int.h"
#include "SRTO_cfg.h"
#include "SRTO_priv.h"

tstrTASK *Queue[MAX_TASK_NB];

void SRTO_voidInit(void)
{
    u8 u8IndexLoc;
    TIMER0_voidInit();
    TIMER0_voidOVCallBack(SRTO_voidScheduler);

    for (u8IndexLoc = 0; u8IndexLoc < TASK_NB; u8IndexLoc++)
    {

        Queue[u8IndexLoc] = &astrTask[u8IndexLoc];
    }

    for (u8IndexLoc = TASK_NB; u8IndexLoc < MAX_TASK_NB; u8IndexLoc++)
    {

        Queue[u8IndexLoc] = NULL;
    }
}

ERRORSTATUS SRTO_enuPlayTask(u16 u16PriorityCpy)
{

    ERRORSTATUS enuErrorStateLoc = OK;

    if (u16PriorityCpy >= MAX_TASK_NB)
    {
        enuErrorStateLoc = INDEX_OUT_OF_RANGE;
    }
    else if (Queue[u16PriorityCpy] == NULL)
    {
        enuErrorStateLoc = NOK;
    }
    else
    {
        Queue[u16PriorityCpy]->Status = RUN;
        enuErrorStateLoc = OK;
    }
    return enuErrorStateLoc;
}

ERRORSTATUS SRTO_enuPauseTask(u16 u16PriorityCpy)
{

    ERRORSTATUS enuErrorStateLoc = OK;
    if (u16PriorityCpy >= MAX_TASK_NB)
    {
        enuErrorStateLoc = INDEX_OUT_OF_RANGE;
    }
    else if (Queue[u16PriorityCpy] == NULL)
    {
        enuErrorStateLoc = NOK;
    }
    else
    {
        Queue[u16PriorityCpy]->Status = WAIT;
    }

    return enuErrorStateLoc;
}

ERRORSTATUS SRTO_enuDeleteTask(u16 u16PriorityCpy)
{
    ERRORSTATUS enuErrorStateLoc = OK;

    if (u16PriorityCpy >= MAX_TASK_NB)
    {
        enuErrorStateLoc = INDEX_OUT_OF_RANGE;
    }
    else if (Queue[u16PriorityCpy] == NULL)
    {
        enuErrorStateLoc = NOK;
    }
    else
    {
        Queue[u16PriorityCpy] = NULL;
    }

    return enuErrorStateLoc;
}

ERRORSTATUS SRTO_enuCreateTask(u16 u16PriorityCpy, tstrTASK *pstrTaskCpy)
{

    ERRORSTATUS enuErrorStateLoc = OK;

    if (u16PriorityCpy >= MAX_TASK_NB)
    {
        enuErrorStateLoc = INDEX_OUT_OF_RANGE;
    }
    else if (pstrTaskCpy == NULL)
    {
        enuErrorStateLoc = NULL_POINTER;
    }
    else if (Queue[u16PriorityCpy])
    {
        enuErrorStateLoc = NOK;
    }
    else
    {
        Queue[u16PriorityCpy] = pstrTaskCpy;
    }

    return enuErrorStateLoc;
}

static void SRTO_voidScheduler(void)
{

    u8 u8IndexLoc;
    for (u8IndexLoc = 0; u8IndexLoc < MAX_TASK_NB; u8IndexLoc++)
    {
        if (Queue[u8IndexLoc] != NULL)
        {
            if (Queue[u8IndexLoc]->u16FirstDelay == 0)
            {

                if (Queue[u8IndexLoc]->Status == RUN)
                {
                    Queue[u8IndexLoc]->PfTaskFunction();
                }
                else
                {
                }
                if (Queue[u8IndexLoc]->u16Periodicity != 0)
                {

                    Queue[u8IndexLoc]->u16FirstDelay = Queue[u8IndexLoc]->u16Periodicity - 1;
                }
                else
                {
                }
            }
            else
            {
                Queue[u8IndexLoc]->u16FirstDelay--;
            }
        }
        else
        {
            /* NO ACTION */
        }
    }
}
