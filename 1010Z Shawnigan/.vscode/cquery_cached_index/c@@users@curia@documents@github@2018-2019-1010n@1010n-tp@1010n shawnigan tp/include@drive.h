#ifndef _DRIVE_H_
#define _DRIVE_H_

#include "main.h"

class driveClass {

private:

int angle;
int encL;
int encR;

public:

void driveTime(int);
void drive(int target, int timeout, float kp, float kd) float;
void driveSide(int target, int timeout, float kp, float kd) float;
void turn(int target, int timeout, float kp, float kd) float;

};

#endif
