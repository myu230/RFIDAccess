#include "Doorlock.h"

Servo g_servo;

void setupDoorlock(int servoOutputPin) {
	g_servo.attach(servoOutputPin);
	g_servo.write(DOOR_INITIAL_ANGLE);
}

void openDoor() {
	g_servo.write(DOOR_OPEN_ANGLE);
}

void closeDoor() {
	g_servo.write(DOOR_INITIAL_ANGLE);
}