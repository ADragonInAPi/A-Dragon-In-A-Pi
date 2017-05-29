/*
 * libdpi.c - The main library for the Dragon In a Pi.
 * 		As of current, this code is under the public domain.
 */

#include "libdpi.h"

/*
 * setPos(motor, position) - sets motors to a specified position
 */

int setPos(int motor, unsigned int position) {
	int motorPin = (motor == 15) ? 16 : motor;
	int serial = serialOpen("/dev/ttyAMA0", 300);

	if(serial == -1) {
		return 1;
	}
	// Set the motor's enable pin high
	digitalWrite(motorPin, 1);
	serialPutchar(serial, (unsigned char) position);
	digitalWrite(motorPin, 0);
	serialClose(serial);

	return 0;
}

/*
 * resetmotors() - resets all servos to their default positions. (Note: we can set these as desired when we get a prototype.
 * 		For now, this just sets them all to zero.) Must be called before any other function as it also sets up GPIO.
 */

int resetmotors(void) {
	int i;

	if(wiringPiSetup() == -1) {
		return 1;	// Fail on setup not working
	}

	for(i = 0; i <= 14; i++) {
		pinMode(i, OUTPUT);
	}
	pinMode(16, OUTPUT);

	// Now set the motors to defaults
	for(i = 0; i <= 15; i++) {
		setPos(i, 0);
	}

	return 0;
}
