/*
Name:		Lab003L4.ino
Created:	5/30/2018 4:32:10 PM
Author:	chris dyck
Description: This program will read the data from the rotation sensor and display the result to the serial monitor.

*/

int LED1 = 9; //LED 1 Red
int LED2 = 10; //LED 2 Green
int LED3 = 11; //LED 3 Blue

int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data = 0;           //Used to store data from sensor.
int delayTime = 1000;
int currentLed = LED1;

void setup() { //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop() { //The loop function runs forever	
	data = Read();

	Blink();

}

void Blink() {
	digitalWrite(currentLed, HIGH);
	delay(delayTime);           //Wait 1 second (1000mS) before running again. 
	digitalWrite(currentLed, LOW);
	delay(delayTime);           //Wait 1 second (1000mS) before running again. 
}

int Read() {
	int value = analogRead(rotationPin);  //Read the value from the light sensor and store it in the lightData variable.
	Serial.print("Rotation is = ");
	Serial.println(value);  //Print the data to the serial port.

	if (value > 511) {
		currentLed = LED1;
	}
	else {
		currentLed = LED3;
	}
	Serial.print("Temperature light is = ");  //Print the data to the serial port.
	Serial.println(currentLed);  //Print the data to the serial port.

	return(value);
}
