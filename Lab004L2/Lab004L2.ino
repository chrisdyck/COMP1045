/*
Name:		Lab004L2.ino
Created:	5/30/2018 5:53:28 PM
Author:	chris dyck
*/

int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0;      //This will store the data from the sensor.

void setup() { //The Setup function runs once.
	Serial.begin(9600);
}

void loop() { //The loop function runs forever.
	data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
	Serial.print("Light value = ");
	Serial.print(data);  //Print the data to the serial port.
	Serial.print(", % = ");
	int percentage = map(data, 0, 1023, 0, 100); //Convert sensor value to % 0 - 100
	Serial.println(percentage);  //Print the data to the serial port.
	delay(1000);           //Wait 1 second (1000mS) before running again.
}

