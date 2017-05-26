/*
 * libdpi.c - The main library for the Dragon In a Pi.
 * 			  As of current, this code is under the public domain.
 */
 
 #include <errno.h>
 #include <wiringPi.h>
 #include <wiringSerial.h>

/*
 * setPos(motor, position) - sets motors to a specified position
 */

int setPos(int motor, unsigned int position) {
	// Set the motor's enable pin high
	if(motor == 15) {
		int motorPin = 16;
	}
	else {
		int motorPin = motor
	}
	int serial = serialOpen("/dev/ttyAMA0", 300);
	if(serial == -1) {
		return(1);
	}
	digitalWrite(motorPin, 1);
	serialPutchar(serial, unsigned char position);
	digitalWrite(notorPin, 0);
	serialClose(serial);
	return(0);
}

/*
 * resetmotors() - resets all servos to their default positions. (Note: we can set these as desired when we get a prototype.
 *				   For now, this just sets them all to zero.) Must be called before any other function as it also sets up GPIO.
 */

int resetmotors(void) {
	if(wiringPiSetup() == -1) {
		return(1) 			// Fail on setup not working
	}	
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(14, OUTPUT);
	pinMode(16, OUTPUT);
	// Now set the motors to defaults
    setPos(0, 0);
	setPos(1, 0);
	setPos(2, 0);
	setPos(3, 0);
	setPos(4, 0);
	setPos(5, 0);
	setPos(6, 0);
	setPos(7, 0);
	setPos(8, 0);
	setPos(9, 0);
	setPos(10, 0);
	setPos(11, 0);
	setPos(12, 0);
	setPos(13, 0);
	setPos(14, 0);
	setPos(15, 0);
	return(0);
}
	