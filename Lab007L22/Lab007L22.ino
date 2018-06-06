/*
Name:		Lab007L22.ino
Created:	6/6/2018 5:12:06 PM
Author:	chris
*/
int SW1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int SW2 = 3;    //The SW2 button is connect to pin 3 of the Arduino.

int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5;    //This is the number of milliseconds that it will take between steps during fading.

					  // the setup function runs once when you press reset or power the board
void setup() {
	pinMode(RGBBluePin, OUTPUT);  //Setup red LED pin as an output pin.

	pinMode(SW2, INPUT);  //Setup button1 pin as an input pin.

}

// the loop function runs over and over again until power down or reset
void loop() {

	if (digitalRead(SW2) == LOW) {
		fadeLight(RGBBluePin);
	}

}

void fadeLight(int light) {
	for (int x = 0; x <= 255; x++) { //Fade in red.
		analogWrite(light, x);
		delay(fadeDelay);
	}

	for (int x = 255; x >= 0; x--) { //Fade out red.
		analogWrite(light, x);
		delay(fadeDelay);
	}
}