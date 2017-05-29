/*
 * libdpi.h - for function definitions from libdpi.c
 */

#ifndef LIBDPI_H
#define LIBDPI_H

#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int setPos(int motor, unsigned int position);
int resetmotors(void);

#endif
