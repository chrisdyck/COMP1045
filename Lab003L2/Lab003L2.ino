/*
Name:		Lab003L2.ino
Created:	5/30/2018 4:32:10 PM
Author:	chris dyck
Description: This program will read the data from the rotation sensor and display the result to the serial monitor.

*/

int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data = 0;           //Used to store data from sensor.
int delayTime = 5000;

void setup() { //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop() { //The loop function runs forever	
	data = Read();
	delay(delayTime);           //Wait 1 second (1000mS) before running again. 
}

int Read() {
	int value = analogRead(rotationPin) / 4;  //Read the value from the light sensor and store it in the lightData variable.
	Serial.print("Volume Level is = ");
	Serial.println(value);  //Print the data to the serial port.
	return(value);
}
