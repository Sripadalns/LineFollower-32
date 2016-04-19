/*
 * PortDef.h
 *
 * Created: 19-04-2016 13:49:01
 *  Author: sripals
 */ 


#ifndef PORTDEF_H_
#define PORTDEF_H_


#include <avr/io.h>

#define Left_Input    PINC0
#define Mid_Input     PINC1
#define Right_Input   PINC2


/* Example Configuration

Pin 2 = Logic 1 and Pin 7 = Logic 0 | Clockwise Direction
Pin 2 = Logic 0 and Pin 7 = Logic 1 | Anticlockwise Direction
Pin 2 = Logic 0 and Pin 7 = Logic 0 | Idle [No rotation] [Hi-Impedance state]
Pin 2 = Logic 1 and Pin 7 = Logic 1 | Idle [No rotation]

*/


#define Left_Motor_En1  PINC7
#define Left_Motor_En2  PINC6
#define Right_Motor_En1 PINC5
#define Right_Motor_En2 PINC4

#define Right_Motor 0x01
#define Left_Motor 0x02
#define Both_Motor 0x03






#endif /* PORTDEF_H_ */