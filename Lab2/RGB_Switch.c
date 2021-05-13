/**************************************************************************************
* Control all three RBG-LED with the support of the wiringPi-Library .
* As soon as one button is activated the corresponding LED goes on and stays on		
* for 0.5 second. 
* 07.03.2016
*
* updated 18.07.2019 integrate cntrl-c Handler
*
*/

/**************************************************************************************
* WiringPi PINS - Buttons and Pins for the Colour
LED 1:	Pin 0 RED
		Pin 1 BLUE
		Pin 2 GREEN

LED 2:	Pin 0 RED
		Pin 1 BLUE
		Pin 1 GREEN

Button 1	Input with Pullup
Button 2	Input with Pullup
Button 3	Input with Pullup
***************************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <wiringPi.h>

#define LED1_R 21
#define LED1_G 20
#define LED1_B 17

#define LED2_R 22
#define LED2_G 23
#define LED2_B 24

#define Btn1 13
#define Btn2 04
#define Btn3 06

static int running = 0;

/* Interrupt handler to catch crtl-c		*/
static void __signal_handler(__attribute__((unused)) int dummy){
	running = 0;
	return;
}
 

int main()
{
	printf ("****Raspberry Pi LED and Button Test***\n");
	printf("Press Button to switch on LEDs \n");
	signal(SIGINT, __signal_handler);
	wiringPiSetupGpio();
	pinMode(LED1_R, OUTPUT);
	pinMode(LED1_G, OUTPUT);
	pinMode(LED1_B, OUTPUT);
	pinMode(LED2_R, OUTPUT);
	pinMode(LED2_G, OUTPUT);
	pinMode(LED2_B, OUTPUT);
	
	digitalWrite(LED1_R, LOW);	/* LED1_R off		*/
	digitalWrite(LED1_G, LOW);	/* LED1_G off		*/
	digitalWrite(LED1_B, LOW);	/* LED1_G off		*/
	digitalWrite(LED2_R, LOW);	/* LED2_R off		*/
	digitalWrite(LED2_G, LOW);	/* LED2_G off		*/
	digitalWrite(LED2_B, LOW);	/* LED2_B off		*/

	pullUpDnControl(Btn1, PUD_UP);	/* Activate internal Pullup Resistor 	*/
	pullUpDnControl(Btn2, PUD_UP);
	pullUpDnControl(Btn3, PUD_UP);

	pinMode(Btn1, INPUT);		/* Select Input direction		*/
	pinMode(Btn2, INPUT);
	pinMode(Btn3, INPUT);

	running = 1;
	
	while(running){

		if (digitalRead(Btn1) == LOW) {
            digitalWrite(LED1_G, HIGH);
            digitalWrite(LED2_G, HIGH);
            delay(500);
        }
        else {
            digitalWrite(LED1_G, LOW);
            digitalWrite(LED2_G, LOW);
        }
	
    }
	digitalWrite(LED2_R, LOW);		/* Set all LED to LOW	*/
	digitalWrite(LED2_G, LOW);
	digitalWrite(LED2_B, LOW);

	return 0;
}
