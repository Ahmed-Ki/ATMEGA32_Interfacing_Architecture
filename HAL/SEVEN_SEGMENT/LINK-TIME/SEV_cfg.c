/**********************************************/
/* Author      : Ahmed Khalid                 */
/* Description : Configuration.c file for SEV */
/* Date        : 30 Aug 2019                  */
/* Version     : 1.0V                         */
/**********************************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "SEV_cfg.h"
#include "SEV_priv.h"



/* Array of Structure to map Seven Segment PINS to DIO */

tstr7Seg astr7SegCfg[SEV_u8MAX_NB] = {
	{DIO_PIN_0,DIO_PIN_1,DIO_PIN_2,DIO_PIN_3,DIO_PIN_4,DIO_PIN_5,DIO_PIN_6,DIO_PIN_7},
	
	{DIO_PIN_8,DIO_PIN_9,DIO_PIN_10,DIO_PIN_11,DIO_PIN_12,DIO_PIN_13,DIO_PIN_14,DIO_PIN_15}
};