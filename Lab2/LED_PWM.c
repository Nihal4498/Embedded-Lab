
/**************************************************************
* RGB LED Example Code V1.0 - Lighting RGB-LEDs with PWM
* Single Color, Single LED
* Created for Lab Embedded Computing, HS Ravensburg-Weingarten
* 07.03.2016
***************************************************************/

/**************************************************************************************
* WiringPi PINS - Buttons and Pins for the Colour
LED 1:	Pin 0 RED
		Pin 1 BLUE
		Pin 2 GREEN

LED 2:	Pin 3 RED
		Pin 4 BLUE
		Pin 5 GREEN

Button 1	Pin 6
Button 2	Pin 7
Button 3	Pin 8
***************************************************************************************
*/

#define LED1_R 29
#define LED1_G 28
#define LED1_B 0

#define LED2_R 3
#define LED2_G 4
#define LED2_B 5

#define Btn1 23
#define Btn2 7
#define Btn3 22

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>



int main (void)
{
	int val_PWM = 50;
	printf ("***Raspberry Pi RGB_LED Test with PWM***\n");

	wiringPiSetup();
	pinMode(LED1_R, OUTPUT);
	pinMode(LED1_G, OUTPUT);
	pinMode(LED1_B, OUTPUT);
	pinMode(LED2_R, OUTPUT);
	pinMode(LED2_G, OUTPUT);
	pinMode(LED2_B, OUTPUT);
	
	softPwmCreate(LED1_R, 0,100);
	softPwmCreate(LED1_G, 0,100);
	softPwmCreate(LED1_B, 0,100);

	while(1){
		for (;;)   {
			for (val_PWM = 0 ; val_PWM < 1024 ; ++val_PWM)
			{	
				softPwmWrite(LED1_B, val_PWM);	delay(3);
			}
			delay(500);
			for (val_PWM = 1023 ; val_PWM >= 0 ; --val_PWM)
			{
				softPwmWrite(LED1_B, val_PWM);	delay(3);
			}
			delay(500);
			
			for (val_PWM = 0 ; val_PWM < 1024 ; ++val_PWM)
			{	
				softPwmWrite(LED1_G, val_PWM);	delay(3);
			}
			delay(500);
			for (val_PWM = 1023 ; val_PWM >= 0 ; --val_PWM)
			{
				softPwmWrite(LED1_G, val_PWM);	delay(3);
			}
			delay(500);
			
			for (val_PWM = 0 ; val_PWM < 1024 ; ++val_PWM)
			{	
				softPwmWrite(LED1_R, val_PWM);	delay(3);
			}
			delay(500);
			for (val_PWM = 1023 ; val_PWM >= 0 ; --val_PWM)
			{
				softPwmWrite(LED1_R, val_PWM);	delay(3);
			}
			delay(500);
		} 
	}
	return 0 ;
}

