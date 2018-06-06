/*
Name:		Lab004L42.ino
Created:	5/30/2018 5:53:28 PM
Author:	chris dyck
*/
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int soundPin = 5; //The buzzer is plugged into pin 5 of the Arduino.
int data = 0;      //This will store the data from the sensor.
bool tonePlayed = false;
int LEDRED = 9;
int LEDBLUE = 10;
int LEDGREEN = 11;

void setup() { //The Setup function runs once.
	Serial.begin(9600);
	pinMode(LEDRED, OUTPUT);
	pinMode(LEDBLUE, OUTPUT);
	pinMode(LEDGREEN, OUTPUT);
}

void loop() { //The loop function runs forever.
	data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
	int percentage = map(data, 0, 1023, 0, 100); //Convert sensor value to % 0 - 100

	Serial.print("Light sensor is reading = ");  //Print the data to the serial port.
	Serial.println(percentage);  //Print the data to the serial port.


	if (percentage < 40) {
		Serial.println("Lights off");
		digitalWrite(LEDRED, HIGH);
		digitalWrite(LEDBLUE, LOW);
		digitalWrite(LEDGREEN, LOW);
	}
	else if(percentage >= 40 && percentage < 65)
	{
		Serial.println("Lights medium");
		digitalWrite(LEDRED, LOW);
		digitalWrite(LEDBLUE, HIGH);
		digitalWrite(LEDGREEN, LOW);
	}
	else
	{
		Serial.println("Lights bright");
		digitalWrite(LEDRED, LOW);
		digitalWrite(LEDBLUE, LOW);
		digitalWrite(LEDGREEN, HIGH);
	}

	delay(500);           //Wait 0.5 second (500mS) before running again.
}
