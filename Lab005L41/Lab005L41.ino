/*
Name:		Lab005L41.ino
Created:	5/30/2018 7:49:17 PM
Author:	chris
*/

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int buzzerPin = 5;     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 1000;  //Wait

void setup(void) {    //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop(void) { //The loop function runs forever.
	data = analogRead(tempPin);        //Read from the temperature sensor
	Serial.print("Sensor reading = "); //Serial.print displays to the Serial Monitor.
	Serial.println(data);                //This is the raw analog reading

	// Calculate and display temperature.
	double temperatureC = (5.0 * data * 100.0) / 1024;
	Serial.print(temperatureC); Serial.println(" degrees C");

	if (temperatureC > 25) {
		Serial.println("It's too hot!!!");
		tone(buzzerPin, 500, 1000);
	}
	else
	{
		noTone(buzzerPin);
	}

	delay(waitTime); //Wait waitTime before running again.
}