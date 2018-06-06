/*
Name:		Lab006L41.ino
Created:	5/30/2018 9:02:06 PM
Author:	chris
*/

int redLedPin = 12;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin = 13;  //The green LED is connected pin 13 of the Arduino.

int RGBRED = 9;
int RGBGREEN = 10;

int SW1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int SW2 = 3;    //The SW2 button is connect to pin 3 of the Arduino.

int lightArray[] = { redLedPin, blueLedPin };
int numLights = sizeof(lightArray) / sizeof(lightArray[0]);

int startlightsArray[] = { RGBRED, RGBGREEN };
int numStartLightsArray = sizeof(startlightsArray) / sizeof(startlightsArray[0]);

int waitTime = 1000;

void setup() { //The Setup function runs once.
	pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
	pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
	pinMode(SW1, INPUT);  //Setup button1 pin as an input pin.

	digitalWrite(RGBRED, HIGH);
	delay(2000);
	digitalWrite(RGBRED, LOW);
	digitalWrite(RGBGREEN, HIGH);
}

void loop() { //The loop function runs forever.

	if (digitalRead(SW1) == LOW) {
		delay(2000);
		digitalWrite(redLedPin, LOW);
		digitalWrite(blueLedPin, HIGH);
	}
	
	if (digitalRead(SW2) == LOW) {
		delay(2000);
		digitalWrite(blueLedPin, LOW);
		digitalWrite(redLedPin, HIGH);
	}

}

void lightsOff() {
	Serial.print("Turning off light ");

	for (int i = 0; i < numLights; i++) {
		digitalWrite(lightArray[i], LOW); //Turn on the red LED.
	}

	for (int i = 0; i < numStartLightsArray; i++) {
		digitalWrite(startlightsArray[i], LOW); //Turn on the red LED.
	}
}

void toggleLight(int light) {

	for (int i = 0; i < numLights; i++) {
		if (i != light) {
			digitalWrite(lightArray[i], LOW); //Turn on the red LED.
		}
		else
		{
			digitalWrite(lightArray[light], HIGH); //Turn on the red LED.
		}
		delay(waitTime);
	}

	lightsOff();

}