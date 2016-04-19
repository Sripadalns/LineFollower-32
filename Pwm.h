/*
 * Pwm.h
 *
 * Created: 18-04-2016 14:20:53
 *  Author: sripals
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <util/delay.h>


/* Initialize PWM module */
void InitPWM(void);

/* Set Duty */
void SetPWMDuty(uint8_t duty , uint8_t channel);




#endif /* PWM_H_ */