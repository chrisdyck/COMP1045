/*
Name:		Lab007L3.ino
Created:	6/6/2018 5:12:06 PM
Author:	chris
*/

int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int rotationPin = A0;
int data = 0;

void setup() {
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

// the loop function runs over and over again until power down or reset
void loop() {
	data = Read();
	analogWrite(RGBGreenPin, data);
	delay(500);
}

int Read() {
	int rawdata = analogRead(rotationPin);// / 4;  //Read the value from the light sensor and store it in the lightData variable.
	int value = map(rawdata, 0, 1023, 0, 255);
	Serial.print("Volume Level is = ");
	Serial.println(value);  //Print the data to the serial port.
	return(value);
}
