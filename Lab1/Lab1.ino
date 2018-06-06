/*
Name:		Lab 1.L21.ino
Created:	5/30/2018 10:42:35 AM
Author:	chris dyck
Description: 
*/
int LED1 = 13; //The blue LED is connected pin 2 of the Arduino.
int onTime = 500; //500 milliseconds
int offTime = 950; //950 milliseconds

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED1, OUTPUT);  //Setup Blue LED pin as an output pin.  
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(LED1, HIGH);  //Turn on the blue LED.
	Serial.println("Light on");
	delay(onTime);                   //Wait onTime.
	digitalWrite(LED1, LOW);   //Turn off the blue LED.
	Serial.println("Light off");
	delay(offTime);                  //Wait offTime.
}
