/*
Name:		Sketch1.ino
Created:	5/23/2018 4:50:11 PM
Author:	chris
*/  /*
*      Title: 321Maker Experiment #001 - Blue Blink
*      Description: This program will blink the Blue LED on the 321Maker shield.
*      Tutorial:  http://321maker.com/e/blue-blink
*      Revision Date: January 15, 2016
*      Licence: http://321maker.mit-license.org/
*      Requirements:  Arduino with 321Maker Shield
*/

int blueLedPin = 13; //The blue LED is connected pin 13 of the Arduino.
int onTime = 50;    //This is the number of milliseconds the LED will be on for. 
int offTime = 2000;   //This is the number of milliseconds the LED will be off for. 

void setup() { //The Setup function runs once.
	pinMode(blueLedPin, OUTPUT);  //Setup Blue LED pin as an output pin.  
}

void loop() { //The loop function runs forever.
	for (int i = 0; i < 3; i++) {
		digitalWrite(blueLedPin, HIGH);  //Turn on the blue LED.
		delay(1000);                   //Wait onTime.
		digitalWrite(blueLedPin, LOW);   //Turn off the blue LED.
		delay(1000);                  //Wait offTime.
	}

	for (int i = 0; i < 3; i++) {
		digitalWrite(blueLedPin, HIGH);  //Turn on the blue LED.
		delay(100);                   //Wait onTime.
		digitalWrite(blueLedPin, LOW);   //Turn off the blue LED.
		delay(100);                  //Wait offTime.
	}
}
