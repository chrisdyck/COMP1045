/*
Name:		Lab003L4.3.ino
Created:	5/30/2018 4:32:10 PM
Author:	chris dyck
Description: Tone generator Challenge- Write a program that will output a sound using the buzzer
(D5). The sound of the buzzer should vary with the value of the rotation dial.

*/


int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int soundPin = 5; //The sound speaker
int volume = 0;

void setup() { //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
	pinMode(soundPin, OUTPUT);
}

void loop() { //The loop function runs forever	

	volume = Read(); //Get current rotation
	tone(soundPin, volume, 500); //Write the brightness to the LED
	delay(50);
}

int Read() {
	int value = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
	Serial.print("Rotation is = ");
	Serial.println(value);  //Print the data to the serial port.

	return(value);
}
