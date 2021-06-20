/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Program file for GIE */
/* Date        : 6 Sep 2019           */
/* Version     : 1.0V                 */
/**************************************/



#include "STD_types.h"
#include "BIT_math.h"

#include "GIE_int.h"
#include "GIE_cfg.h"
#include "GIE_priv.h"



/* Enable GIE */
void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}



/* Disable GIE */
void GIE_voidDisable(void)
{
	CLEAR_BIT(SREG,7);
}
