/*
Name:		Lab005L42.ino
Created:	5/30/2018 7:49:17 PM
Author:	chris
*/

int tempPin = A2;		//The temperature sensor is plugged into pin A2 of the Arduino.
int data;				//This will store the data from the sensor.
int waitTime = 5000;	//Wait

int LEDRED = 9;			//LED 9 for RED light
int LEDBLUE = 10;		//LED 10 for RED light

bool heating = false;	//Flag true if heating
bool cooling = false;	//Flag true if cooling

int coolingLimit = 25;	//Lower limit for cooling

void setup(void) {		//The Setup function runs once.
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
	pinMode(LEDRED, OUTPUT);
	pinMode(LEDBLUE, OUTPUT);
}

void loop(void) {		//The loop function runs forever.
	data = analogRead(tempPin);				//Read from the temperature sensor
	Serial.print("Sensor reading = ");		//Serial.print displays to the Serial Monitor.
	Serial.println(data);					//This is the raw analog reading

	// Calculate and display temperature.
	double temperatureC = (5.0 * data * 100.0) / 1024;
	Serial.print(temperatureC); Serial.println(" degrees C");

	if (temperatureC < coolingLimit) {
		if (heating == false) { //We don't need to turn it on twice
			Serial.println("Furnace on. It's getting hotter now!");
			digitalWrite(LEDRED, HIGH);
			digitalWrite(LEDBLUE, LOW);
			heating = true;
			cooling = false;
		}
	}
	else
	{
		if (cooling == false) { //We don't need to turn it on twice
			Serial.println("Air Conditioner on...");
			digitalWrite(LEDRED, LOW);
			digitalWrite(LEDBLUE, HIGH);
			cooling = true;
			heating = false;
		}
	}

	delay(waitTime); //Wait waitTime before running again.
}