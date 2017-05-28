/*
 * libdpi.c - The main library for the Dragon In a Pi.
 * 			  As of current, this code is under the public domain.
 */

/* 
 *  libdpi.h isn't necessary here because the functions are already defined in this file. We can use it, but the 
 *  compiler may not like it.
 */
#include "libdpi.h"
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

/*
 * setPos(motor, position) - sets motors to a specified position
 */

int setPos(int motor, unsigned int position) {
	// Set the motor's enable pin high
        int motorPin = (motor == 15) ? 16 : motor;
	int serial = serialOpen("/dev/ttyAMA0", 300);
	if(serial == -1) {
		return 1;
	}
	digitalWrite(motorPin, 1);
	serialPutchar(serial, (unsigned char) position);
	digitalWrite(motorPin, 0);
	serialClose(serial);
	return 0;
}

/*
 * resetmotors() - resets all servos to their default positions. (Note: we can set these as desired when we get a prototype.
 *		   For now, this just sets them all to zero.) Must be called before any other function as it also sets up GPIO.
 */

int resetmotors(void) {
    int i;
    if(wiringPiSetup() == -1) {
        return 1; 			// Fail on setup not working
    }
    for(i = 0; i <= 14; i++) {
        pinMode(i, OUTPUT);
    }
    // This is not a bug. I did this because we won't be using the UART's Rx pin as of yet, so I simply set it
    // to be used as a motor enable line to maximize the number of servos we could possibly use.
    pinMode(16, OUTPUT);   

    // Now set the motors to defaults
    for(i = 0; i <= 15; i++) {
        setPos(i, 0);
    }

	return 0;
}
