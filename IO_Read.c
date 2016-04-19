/*
 * IO_Read.c
 *
 * Created: 4/19/2016 10:42:53 AM
 *  Author: My Pc
 */ 

#include <avr/io.h>

#define Left_Input    PORTC.0
#define Mid_Input     PORTC.1
#define Right_Input   PORTC.2


void main()
{

    DDRC = 0xF0;                   //PC as input
    Left_Input = 1;                //enable pull ups for
    Mid_Input  = 1;                //only first 3 pins
	Right_Input= 1;

    while(1)
    {
        /* No Line to follow */
        if( (Left_Input == 0 )  && (Right_Input = 0 ) && (Mid_Input == 0))                                        
        {
           
		   /* Set Duty = 0*; For /
		
		}
		/* Only Mid is High : Go Straight*/
        if( (Left_Input == 0 )  && (Right_Input = 0 ) && (Mid_Input == 1))                                        
        {
           
		   /* Set Duty = 0x80*/
		
		}
		/* Only Mid is High : Go Straight*/
        if( (Left_Input == 0 )  && (Right_Input = 0 ) && (Mid_Input == 1))                                        
        {
           
		   /* Set Duty = 0x80*/
		
		}		   
}
