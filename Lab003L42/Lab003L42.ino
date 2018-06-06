/*
Name:		Lab003L4.2.ino
Created:	5/30/2018 4:32:10 PM
Author:	chris dyck
Description: Light Show Challenge– Write a program that will vary the brightness of the RGB led (D9-
D11), based on the value of the rotation sensor.

*/

//int LED1 = 13; //LED 1 Red
int LED1 = 9; //LED 1 Red
int LED2 = 10; //LED 2 Green
int LED3 = 11; //LED 3 Blue

int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data = 0;           //Used to store data from sensor.
int delayTime = 30;
int currentLed = LED1;
int brightness = 255;

void setup() { //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
	pinMode(LED1, OUTPUT);
}

void loop() { //The loop function runs forever	

	for (int led = LED1; led <= LED3; led++) {
		data = Read(); //Get current rotation
		brightness = data / 4; //Calculate a brightness level
		analogWrite(led, brightness); //Write the brightness to the LED
		delay(50);
	}

}

int Read() {
	int value = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
	Serial.print("Rotation is = ");
	Serial.println(value);  //Print the data to the serial port.

	return(value);
}
