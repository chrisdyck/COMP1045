/*
 Name:		Lab007L4.ino
 Created:	6/6/2018 5:42:51 PM
 Author:	chris
*/

int SW1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.

int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
int rotationPin = A0; //Rotation pin 

int data = 0;
int mode = 0;
int lightArray[] = { RGBRedPin, RGBGreenPin, RGBBluePin };
int numLights = sizeof(lightArray) / sizeof(lightArray[0]);
String lightNameArray[] = { "Red", "Green", "Blue" };
int lightValuesArray[] = { 0, 0, 0 };

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.

	for (int i = 0; i < numLights; i++) {
		pinMode(lightArray[i], OUTPUT);  //Setup RGB LED pins as an output pin.
	}

	pinMode(SW1, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (digitalRead(SW1) == LOW) {

		mode++;
		if (mode >= numLights) {
			mode = 0;
		}
	}

	data = Read();
	lightValuesArray[mode] = data;
	analogWrite(lightArray[mode], data);
	delay(250);
}

int Read() {
	int rawdata = analogRead(rotationPin);// / 4;  //Read the value from the light sensor and store it in the lightData variable.
	int value = map(rawdata, 0, 1023, 0, 255);
	Serial.print("Brightness Level on ");
	Serial.print(lightNameArray[mode]);
	Serial.print(" is ");
	Serial.println(value);  //Print the data to the serial port.
	OutputRGB();
	Serial.println("");  //Print the data to the serial port.
	return(value);
}

void OutputRGB() {
	Serial.print("RGB(");
	for (int i = 0; i < numLights; i++) {
		Serial.print(lightValuesArray[i], OUTPUT);  //Setup RGB LED pins as an output pin.
		if(i < numLights - 1)
			Serial.print(",");
	}
	Serial.print(")");
}
