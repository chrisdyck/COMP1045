/*
 Name:		Lab005L1.ino
 Created:	5/30/2018 7:49:17 PM
 Author:	chris
*/

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 3000;  //Wait
void setup(void) {    //The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop(void) { //The loop function runs forever.
	data = analogRead(tempPin);        //Read from the temperature sensor
	Serial.print("Sensor reading = "); //Serial.print displays to the Serial Monitor.
	Serial.println(data);                //This is the raw analog reading

	// Calculate and display temperature.
	float temperatureC = (5.0 * data * 100.0) / 1024;
	Serial.print(temperatureC); Serial.println(" degrees C");

	// Convert temperature to Fahrenheight and display.
	float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
	Serial.print(temperatureF); Serial.println(" degrees F");

	delay(waitTime); //Wait waitTime before running again.
}