/*
 * PWM.c
 *
 * Created: 18-04-2016 13:56:16
 *  Author: sripals
 */ 

#include "Pwm.h"
#include "Portdef.h"


void InitPWM()
{
   /*
   @ Page 80 of Atmega 32 data sheet
   
   TCCR0 - Timer Counter Control Register (TIMER0)
   -----------------------------------------------
   BITS DESCRIPTION
   

   NO:   NAME   DESCRIPTION
   --------------------------
   BIT 7 : FOC0   Force Output Compare [Not used in this example]
   BIT 6 : WGM00  Wave form generartion mode [SET to 1]
   BIT 5 : COM01  Compare Output Mode        [SET to 1]
   BIT 4 : COM00  Compare Output Mode        [SET to 0]

   BIT 3 : WGM01  Wave form generation mode [SET to 1]
   BIT 2 : CS02   Clock Select               [SET to 0]
   BIT 1 : CS01   Clock Select               [SET to 1]
   BIT 0 : CS00   Clock Select               [SET to 1]

   The above settings are for
   --------------------------

   Timer Clock = CPU Clock (Pre scalling by 64)
   Mode        = Fast PWM
   PWM Output  = Non Inverted

   */


   TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS02);
   TCCR2|=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS22);

   //Set OC0 PIN as output. It is  PB3 on ATmega16 ATmega32

   DDRB|=(1<<PB3); /*Right Motor*/
   DDRD|=(1<<PD7); /*Left Motor*/
}

/******************************************************************
Sets the duty cycle of output. 

Arguments
---------
duty: Between 0 - 255

0= 0%

255= 100%

The Function sets the duty cycle of pwm output generated on OC0 PIN
The average voltage on this output pin will be

         duty
 Vout=  ------ x 5v
         255 

This can be used to control the brightness of LED or Speed of Motor.
*********************************************************************/

void SetPWMDuty(uint8_t duty,uint8_t channel)
{
     if ( channel == Both_Motor)
	 {
	    /*Set Both The channels with same duty*/
		OCR0=duty;
		OCR2=duty;
	 }
	 else if ( channel == Right_Motor) /*Right Motor*/
	 {
	    /*Set First channel duty*/
		OCR0=duty;
	 }	
	 else if( channel == Left_Motor) /*Left Motor*/
	 {
	    /*Set second channel duty*/
		OCR2=duty;
	 }	
	 else
	 {
	   /* Do Nothing*/
	 }		  
	  
}

