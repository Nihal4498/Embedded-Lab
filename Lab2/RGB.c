/**************************************************************************************
* Control two RBG-LED with the support of the wiringPi-Libraray .
* In a sequence the first LED should flash red an the second LED green
* 07.03.2016
* updated 18.07.2019 integrate cntrl-c Handler
*/
/**************************************************************************************
* WiringPi PINS - Buttons and Pins for the Colour
LED 1:	Pin 0 RED
		Pin 1 BLUE
		Pin 2 GREEN

LED 2:	Pin 0 RED
		Pin 1 BLUE
		Pin 2 GREEN

Button 1	Input with Pullup
Button 2	Input with Pullup
Button 3	Input with Pullup
***************************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <wiringPi.h>

#define LED1_B 17
#define LED1_R 20
#define LED1_G 21

#define LED2_R 23
#define LED2_G 24
#define LED2_B 22

#define Btn1 13
#define Btn2 04
#define Btn3 06

static int running = 0;

	/* Interrupt handlet to catch crtl-c		*/
	static void __signal_handler(__attribute__((unused)) int dummy){
	running = 0;
	return;
}


int main()
{
	signal(SIGINT, __signal_handler);
	printf ("***Raspberry Pi RGB_LED Test***\n");
	wiringPiSetupGpio();
	pinMode(LED1_R, OUTPUT);
	pinMode(LED1_G, OUTPUT);
	pinMode(LED1_B, OUTPUT);
	pinMode(LED2_R, OUTPUT);
	pinMode(LED2_G, OUTPUT);
	pinMode(LED2_B, OUTPUT);

	running = 1;				/* Running until ctrl-c	*/

	digitalWrite(LED1_R, LOW);	/* LED1_R off		*/
	digitalWrite(LED1_G, LOW);	/* LED1_G off		*/
	digitalWrite(LED1_B, LOW);	/* LED1_G off		*/
	digitalWrite(LED2_R, LOW);	/* LED2_R off		*/
	digitalWrite(LED2_G, LOW);	/* LED2_G off		*/
	digitalWrite(LED2_B, LOW);	/* LED2_B off		*/


	while(running){
		
		digitalWrite(LED1_R, HIGH); 
		digitalWrite(LED2_G, HIGH); delay(500);
		digitalWrite(LED1_R, LOW); 
		digitalWrite(LED2_G, LOW); delay(500);
		
		digitalWrite(LED1_G, HIGH); 
		digitalWrite(LED2_B, HIGH); delay(500);
		digitalWrite(LED1_G, LOW); 
		digitalWrite(LED2_B, LOW); delay(500);
		
		digitalWrite(LED1_B, HIGH); 
		digitalWrite(LED2_R, HIGH); delay(500);
		digitalWrite(LED1_B, LOW); 
		digitalWrite(LED2_R, LOW); delay(500);
        }

	digitalWrite(LED1_R, LOW);	/* LED1_R off		*/
	digitalWrite(LED1_G, LOW);	/* LED1_G off		*/
	digitalWrite(LED1_B, LOW);	/* LED1_G off		*/
	digitalWrite(LED2_R, LOW);	/* LED2_R off		*/
	digitalWrite(LED2_G, LOW);	/* LED2_G off		*/
	digitalWrite(LED2_B, LOW);	/* LED2_B off		*/
	printf("\nRGB_LED Test stopped\n");
	return 0;
}
