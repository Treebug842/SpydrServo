#include "SpydrServo.h"

SpydrServo myServo;							// Create the myServo object

void setup()
{
	myServo.attach(3, A0);				// Attach the servo pin to 3, and the pot pin to A0
	Serial.begin(9600);						// Begin serial at 9600 baud rate
}

void loop() 
{
	potValue = myServo.read();		// Sets potValue to the value of the potentiometer
	myServo.write(40);						// Writes servo to 40 degrees (within 8 degree margine for error)
	Serial.println(potValue);			// Prints the potValue to serial monitor
	delay(1000);									// Waits 1 second (1000 microseconds)
	
	potValue = myServo.read();		// Sets potValue to the value of the potentiometer
	myServo.write(140);						// Writes servo to 140 degrees (within 8 degree margine for error)
	Serial.println(potValue);			// Prints the potValue to serial monitor
	delay(1000);									// Waits 1 second (1000 microseconds)
}

/*
Take note that the servo can only go from 5-175 degrees
This is to prevent the servo from over turning the potentiometer
*/