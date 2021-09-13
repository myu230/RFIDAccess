#ifndef DOORLOCK_H
#define DOORLOCK_H

#include <Servo.h>

// !IMPORTANT!
void setupDoorlock(int servoOutputPin); // must call this function in setup before using any other functions below

#define DOOR_INITIAL_ANGLE 10
#define DOOR_OPEN_ANGLE 90

void openDoor();
void closeDoor();

#endif // !DOORLOCK_H
