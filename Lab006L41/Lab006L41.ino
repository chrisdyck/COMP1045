/*
Name:		Lab006L41.ino
Created:	5/30/2018 9:02:06 PM
Author:	chris
*/

int redLedPin = 12;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin = 13;  //The green LED is connected pin 13 of the Arduino.

int SW1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.

int lightArray[] = { redLedPin, blueLedPin };
int numLights = sizeof(lightArray) / sizeof(lightArray[0]);
int waitTime = 1000;

void setup() { //The Setup function runs once.
	pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
	pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
	pinMode(SW1, INPUT);  //Setup button1 pin as an input pin.
}

void loop() { //The loop function runs forever.

	if (digitalRead(SW1) == LOW) {
		long coinFlip = rand() % 2;
		
		Serial.println(coinFlip);

		toggleLight(coinFlip);
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

	lightsOff();

}