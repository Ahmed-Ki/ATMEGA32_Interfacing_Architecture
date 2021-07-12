/********************************************/
/* Author      : Ahmed Khalid               */
/* Description : Configuration file for ADC */
/* Date        : 7 Sep 2019                 */
/* Version     : 1.0V                       */
/********************************************/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/*           Choose voltage reference for ADC        */
/* Voltage reference can be:                         */ 
/*                           AREF   (Change Voltage) */
/*                           AVCC   (5v)             */
/*                           INTERNAL (2.56v)        */

#define ADC_VOLTAGE_REFERENCE   AVCC

/*      Choose result adjustment for ADC       */
/* Adjustment can be :                         */
/*                      LEFT_ADJUSTMENT        */
/*                      RIGHT_ADJUSTMENT       */
/***********************************************/
/* Note: The preffered adjustment for 8bit     */
/*       resolution is LEFT_ADJUSTMENT and for */
/*       10bit resolution is RIGHT_ADJUSTMENT  */

#define ADC_RESULT_ADJUSTMENT   RIGHT_ADJUSTMENT


/*      Single Input Positive Channel     */
/* Choose Channel Number:                 */
/*                        ADC0            */
/*                        ADC1            */
/*                        ADC2            */
/*                        ADC3            */
/*                        ADC4            */
/*                        ADC5            */
/*                        ADC6            */
/*                        ADC7            */

#define ADC_CHANNEL_NUMBER			ADC0


/*             ADC Auto Trigger Source              */
/* Available options:                               */
/*                    FREE_RUNNING_MODE 			*/	 
/*                    ANALOG_COMPARATOR				*/ 
/*                    EXTERNAL_INTERRPUT_REQUEST_0 	*/ 
/*                    TIMER_COUNTER_0_COMPARE_MATCH	*/ 
/*                    TIMER_COUNTER_0_OVERFLOW		*/ 
/*                    TIMER_COUNTER_COMPARE_MATCH_B	*/ 
/*                    TIMER_COUNTER_1_OVERFLOW		*/ 
/*                    TIMER_COUNTER_1_CAPTURE_EVENT */	 

#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE


/*               ADC Prescaler Select             */
/* Available Sampling Speeds:                     */
/*                            DIVIDE_BY_2         */
/*                            DIVIDE_BY_4         */
/*                            DIVIDE_BY_8         */
/*                            DIVIDE_BY_16        */
/*                            DIVIDE_BY_32        */
/*                            DIVIDE_BY_64        */
/*                            DIVIDE_BY_128       */
/**************************************************/
/* Note: This option divides the micro controller */
/*       frequency by one of the above division   */
/*       factors so the micro controller can      */
/*       match the speed of the ADC peripheral    */


#define ADC_PRESCALER				DIVIDE_BY_64




#endif