/**************************************/
/* Author      : Ahmed Khalid         */
/* Description : Private file for GIE */
/* Date        : 6 Sep 2019           */
/* Version     : 1.0V                 */
/**************************************/


#ifndef GIE_PRIV_H
#define GIE_PRIV_H


/* Memory mapped Status Register (SREG) address to Enable/Disbale Global Interrupt Enable */

#define	SREG	*((volatile u8 *) 0x5F)

#endif
