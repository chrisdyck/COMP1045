/*
Name:		Lab006L2.ino
Created:	5/30/2018 9:02:06 PM
Author:	chris
*/

int redLedPin = 12;  //The red LED is connected pin 12 of the Arduino.
int blueLedPin = 13;  //The blue LED is connected pin 13 of the Arduino.
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.

int currentLight = redLedPin;
int currentButton = button1Pin;

long timerStart = 0;
bool timerRunning = false;
bool buttonPressIgnored = false;
long time = 0;
long timerDiff = 0;

void setup() { //The Setup function runs once.
	pinMode(redLedPin, OUTPUT);  //Setup red LED pin as an output pin.
	pinMode(blueLedPin, OUTPUT);  //Setup blue LED pin as an output pin.
	pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
	pinMode(button2Pin, INPUT);  //Setup button2 pin as an input pin.
	//wd_timer_id = timer.setInterval(3000, lightOff);

}

void loop() { //The loop function runs forever.

	toggleLight(button1Pin, blueLedPin);

	toggleLight(button2Pin, redLedPin);

	if (timerDiff >= 3000 && timerRunning == true) {
		Serial.println("Timed out...");
		lightOff();
	}
	else if (timerRunning == true && timerStart > 0){
		time = millis(); //Update time
		timerDiff = time - timerStart;
	}

}

void lightOff() {
	Serial.println("Timer callback");
	Serial.print("Turning off light ");
	Serial.println(currentLight);

	digitalWrite(currentLight, LOW);  //Turn off the red LED.

	timerRunning = false;
	timerStart = 0;
	timerDiff = 0;
}

void toggleLight(int buttonpin, int light) {

	if (digitalRead(buttonpin) == LOW) {
		if (timerRunning == false) { //A button was already pressed
			currentButton = buttonpin;
			currentLight = light;
			digitalWrite(light, HIGH); //Turn on the red LED.
			Serial.println("Timer started...");
			timerStart = millis();

			timerRunning = true;
			buttonPressIgnored = false;
		}
		else{
			if (buttonPressIgnored == false) {
				Serial.print("Button press ignored at ");
				Serial.println(timerStart);
				buttonPressIgnored = true;
			}
		}
	}

}