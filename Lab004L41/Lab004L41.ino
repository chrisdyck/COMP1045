/*
Name:		Lab004L41.ino
Created:	5/30/2018 5:53:28 PM
Author:	chris dyck
*/
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int soundPin = 5; //The buzzer is plugged into pin 5 of the Arduino.
int data = 0;      //This will store the data from the sensor.
bool tonePlayed = false;

void setup() { //The Setup function runs once.
	Serial.begin(9600);
}

void loop() { //The loop function runs forever.
	data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.

	Serial.print("Light sensor is reading = ");  //Print the data to the serial port.
	Serial.println(data);  //Print the data to the serial port.

	int percentage = map(data, 0, 1023, 0, 100); //Convert sensor value to % 0 - 100

	if (percentage > 50) {
		Serial.println("Lights on");
		if (tonePlayed == false) {
			tone(soundPin, 100, 50); //Write the brightness to the LED
			tonePlayed = true;
			Serial.println("Tone played");
		}
	}
	else
	{
		Serial.println("Lights off");
		noTone(soundPin);
		tonePlayed = false;
	}

	delay(500);           //Wait 0.5 second (500mS) before running again.
}
