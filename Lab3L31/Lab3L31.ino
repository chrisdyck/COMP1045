/*
Name:		Lab3L31.ino
Created:	5/23/2018 5:40:22 PM
Author:	chris
*/
int LED1 = 2; //The blue LED is connected pin 2 of the Arduino.
int LED2 = 4; //The blue LED is connected pin 4 of the Arduino.
int LED3 = 8; //The blue LED is connected pin 4 of the Arduino.
int onTime = 1500;    //This is the number of milliseconds the LED will be on for. 
int offTime = 500;    //This is the number of milliseconds the LED will be on for. 
int leds[] = { LED1, LED2, LED3 };
String flashing = "Flashing == ";
					   // the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED1, OUTPUT);  //Setup Red LED pin as an output pin.  
	pinMode(LED2, OUTPUT);  //Setup Blue LED pin as an output pin.  
	pinMode(LED3, OUTPUT);  //Setup Green LED pin as an output pin.  

}

// the loop function runs over and over again until power down or reset
void loop() {
	for (int i = 0; i < 15; i++) {

		int randNum = rand() % 3;
		LightFlash(leds[randNum]);
	}
}

void LightFlash(int port) {
	Serial.println(String(flashing + port));
	digitalWrite(port, HIGH);  //Turn on the blue LED.
	delay(onTime);                   //Wait onTime.
	digitalWrite(port, LOW);   //Turn off the blue LED.
	delay(offTime);                  //Wait offTime.

}