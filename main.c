/*
 * main.c
 *
 * Created: 4/14/2016 11:28:07 AM
 *  Author: My Pc
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "ultrtasound.h"
#include "Pwm.h"
#include "Portdef.h"


 
int main(){
    
	/*Initializations */
	DDRC        = 0xF0;  
	PORTC       = 0x00;              
    
	int distance_in_cm=0;
	
	/*Initialize PWM*/
	InitPWM();
	SetPWMDuty(0,Both_Motor);
	PORTC |= (1<< Left_Motor_En1)|(1<< Left_Motor_En2)|(1<< Right_Motor_En1)|(1<< Right_Motor_En2);
	
	/*Initialize Echo*/
	
    
    while(1)
    {
        /*Call Echo Sensor and check that no blocks*/
		distance_in_cm=read_ultrasound();
        		
		if (distance_in_cm == TRIG_ERROR ) 
        {
           _delay_ms(DELAY_BETWEEN_TESTS);
        }
		/*No Obstacles . So follow the line*/
		else if( (distance_in_cm > 5 ) || (distance_in_cm == ECHO_ERROR) )
		{
		   /*There is no Line. So Stop*/
		   if( (Left_Input == 0) && (Right_Input == 0) && (Mid_Input == 0) )
		   {
		      PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Left_Motor_En2)|(1<< Right_Motor_En1)|(1<< Right_Motor_En2);
			  SetPWMDuty(0,Both_Motor);
			  
		   }
		    /*Straight Line. Run both Motors at 80% Duty Cycle*/
		   else if( (Left_Input == 0) && (Right_Input == 0) && (Mid_Input == 1) )
		   {
		      PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Right_Motor_En1);
			  SetPWMDuty(0xCD,Both_Motor);
			  
		   }
		   /*Right Curve. Run Left Motors at 30% Duty Cycle.Right Motor at 0 % Duty*/
		   else if( (Left_Input == 0) && (Right_Input == 1) && (Mid_Input == 0) )
		   {
		      
			  PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Right_Motor_En1)|(1<< Right_Motor_En2);
			  SetPWMDuty(0,Right_Motor);
			  SetPWMDuty(0x4C,Left_Motor);
			  
		   }
		   /*Left Curve. Run Right Motors at 30% Duty Cycle.Left Motor at 0 % Duty*/
		   else if( (Left_Input == 1) && (Right_Input == 0) && (Mid_Input == 0) )
		   {
		      PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Right_Motor_En1)|(1<< Left_Motor_En2);
			  SetPWMDuty(0x4C,Right_Motor);
			  SetPWMDuty(0,Left_Motor);
		   }
		   /*Right Curve. Run Left Motors at 30% Duty Cycle.Right Motor at 10 % Duty*/
		   else if( (Left_Input == 0) && (Right_Input == 1) && (Mid_Input == 1) )
		   {
		      
			  PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Right_Motor_En1);
			  SetPWMDuty(0x19,Right_Motor);
			  SetPWMDuty(0x4C,Left_Motor);
			  
		   }
		   /*Left Curve. Run Right Motors at 30% Duty Cycle.Left Motor at 0 % Duty*/
		   else if( (Left_Input == 1) && (Right_Input == 0) && (Mid_Input == 1) )
		   {
		      PORTC &= 0x0F;
			  PORTC |= (1<< Left_Motor_En1)|(1<< Right_Motor_En1);
			  SetPWMDuty(0x4C,Right_Motor);
			  SetPWMDuty(0x19,Left_Motor);
		   }
		   else
		   {
			   /*Do Nothing*/
			   
		   }
		
		}			
        else /*Obstacle very close don't move */
        {
           /* Blow Horn & Stop Motor*/
		   SetPWMDuty(0,Both_Motor);
		   PORTC |= (1<< Left_Motor_En1)|(1<< Left_Motor_En2)|(1<< Right_Motor_En1)|(1<< Right_Motor_En2);
        }
    }
    return 0;
}