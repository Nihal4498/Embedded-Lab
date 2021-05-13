
/**************************************************************
* RGB LED Example Code V1.0 - Lighting RGB-LEDs with PWM
* Single Color, Single LED
* Created for Lab Embedded Computing, HS Ravensburg-Weingarten

***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

/**********************************
WIRING PI PINS - Buttons and Colors
LED 1 : Pin 0 RED
PIN 1 BLUE
PIN 2 GREEN
LED 2 : PIN 3 RED
PIN 4 BLUE
PIN 5 GREEN -
Button 1 : PIN 23
Button 2 : PIN 7
Button 3 : PIN 22
***********************************/

#define LED1_R 0
#define LED1_G 28
#define LED1_B 29
#define LED2_R 3
#define LED2_G 4
#define LED2_B 5


int main (void)
{
	int val_R, val_G, val_B;

	printf ("***Reading Colorvalues from the Terminal***\n");

	wiringPiSetup();
	pinMode(LED1_R, OUTPUT);
	pinMode(LED1_G, OUTPUT);
	pinMode(LED1_B, OUTPUT);
	softPwmCreate(LED1_R, 0,100);
	softPwmCreate(LED1_G, 0,100);
	softPwmCreate(LED1_B, 0,100);
	softPwmWrite(LED1_R, 0);
	softPwmWrite(LED1_G, 0);
	softPwmWrite(LED1_B, 0);
	delay(200);


	while(1)
	{
		printf("Please give the R-, G-, B-Value separated by Commas (Range 0 - 100) \n ");
		scanf("%d, %d, %d", &val_R, &val_G, &val_B);
		softPwmWrite(LED1_R, val_R);
		softPwmWrite(LED1_G, val_G);
		softPwmWrite(LED1_B, val_B); delay(2000);
	}
	return 0 ;
}

