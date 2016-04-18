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
 
int main(){
    int distance_in_cm=0;
    
    while(1)
    {
        distance_in_cm=read_ultrasound();
        if ( (distance_in_cm == TRIG_ERROR ) || (distance_in_cm == ECHO_ERROR)  || (distance_in_cm > 5 ) )
        {
           _delay_ms(DELAY_BETWEEN_TESTS);
        }
        else 
        {
           // Blow Horn & Stop Motor
        }
    }
    return 0;
}