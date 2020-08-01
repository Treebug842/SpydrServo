#include <SpydrServo.h>

SpydrServo myServo;						// Creates myServo object

void setup() 
{
	myServo.attach(5, A2);			// Attaches servo pin to 5, and pot pin to A2
}

void loop() 
{
	myServo.write(20);				// Writes myServo to 20 degrees (with 8 degree marine for error)
	delay(1000);							// Waits 1 second (1000 microseconds)
	myServo.write(160);				// Writes myServo to 160 degrees (with 8 degree marine for error)
	delay(1000);							// Waits 1 second (1000 microseconds)
}

/*
Take note that the servo can only go from 5-175 degrees
This is to prevent the servo from over turning the potentiometer
*/