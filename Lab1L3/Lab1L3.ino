/*
Name:		Lab 1.L3.ino
Created:	5/30/2018 10:42:35 AM
Author:	chris dyck
*/
int LED1 = 13; //The blue LED is connected pin 2 of the Arduino.
int onTime = 1000; //500 milliseconds
int offTime = 100; //950 milliseconds
int onTimeSlow = 1000; //500 milliseconds
int offTimeSlow = 1000; //950 milliseconds

				   // the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED1, OUTPUT);  //Setup Blue LED pin as an output pin.  
}

// the loop function runs over and over again until power down or reset
void loop() {
	for (int i = 0; i < 3; i++) {
		digitalWrite(LED1, HIGH);  //Turn on the blue LED.
		Serial.println("Light on Slow");
		delay(onTimeSlow);                   //Wait onTime.
		digitalWrite(LED1, LOW);   //Turn off the blue LED.
		Serial.println("Light off Slow");
		delay(offTimeSlow);                  //Wait offTime.
	}
	for (int i = 0; i < 3; i++) {
		digitalWrite(LED1, HIGH);  //Turn on the blue LED.
		Serial.println("Light on Fast");
		delay(onTime);                   //Wait onTime.
		digitalWrite(LED1, LOW);   //Turn off the blue LED.
		Serial.println("Light off Fast");
		delay(offTime);                  //Wait offTime.
	}

}
