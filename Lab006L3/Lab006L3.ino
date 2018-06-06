/*
Name:		Lab006L3.ino
Created:	5/30/2018 9:02:06 PM
Author:	chris
*/

int redLedPin = 9;  //The red LED is connected pin 9 of the Arduino.
int greenLedPin = 10;  //The green LED is connected pin 10 of the Arduino.
int blueLedPin = 11;  //The blue LED is connected pin 11 of the Arduino.
int SW1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.

float waitTime = 1000 / 3;

int lightArray[] = { redLedPin, greenLedPin, blueLedPin };
int numLights = sizeof(lightArray) / sizeof(lightArray[0]);

void setup() { //The Setup function runs once.
	pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
	pinMode(greenLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
	pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
	pinMode(SW1, INPUT);  //Setup button1 pin as an input pin.
}

void loop() { //The loop function runs forever.

	if (digitalRead(SW1) == LOW) {
		for (int i = 0; i < numLights; i++) {
			toggleLight(i);
		}
	}

}

void lightsOff() {
	Serial.print("Turning off light ");

	for (int i = 0; i < numLights; i++) {
		digitalWrite(lightArray[i], LOW); //Turn on the red LED.
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

	delay(waitTime);

	lightsOff();

}