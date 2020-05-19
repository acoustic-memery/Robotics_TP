#include "main.h"

//Expo Code --USELESS--
/*int expDrive (int joyVal, float driveExp, int joyDead, int motorMin) {
    int joySign;
    int joyMax = 127 - joyDead;
    int joyLive = abs(joyVal) - joyDead;
    if (joyVal > 0) {joySign = 1;}
    else if (joyVal < 0) {joySign = -1;}
    else {joySign = 0;}
    int power = joySign * (motorMin + ((100 - motorMin) * pow(joyLive, driveExp) / pow(joyMax, driveExp)));
    return power;
} //END int expDrive*/

//Drive Expo Variables
const int cJoyDead = 8; // joystick range in which movement is considered accidental
const int cMotorMin = 15; // minimum drive motor power
const float cDriveExp = 1.5; // exponent for drive power calculations  (1 = linear, 2 = squared) //1.4

int fwVel = 600;
int angle = 0;


void punch_task(void*parameter) {
int reload =1;
  while(true) {
    

    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
      punchMtrL.move(200);
      punchMtrL.tare_position();
      
    }
    else if ((master.get_digital(E_CONTROLLER_DIGITAL_R1)))
    {punchMtrL.move_absolute(200, 200);}
    else{
      punchMtrL.move(0);
    }
  

    pros::delay(10);
  }
}
void opcontrol() {
angleMtr.tare_position();
punchMtrL.tare_position();


Task my_task(punch_task, NULL,TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT,"punchtask");
	while (true) {

		//Expo Controller Inputs Drive
    int Y1 = (master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)); //Expo Forward-Backwards
    int X1 = (master.get_analog(E_CONTROLLER_ANALOG_LEFT_X));//Expo Right-Left
    int Z1 = (master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X)); //Expo Yaw

    //Drive Manual
    driveLF.move( Y1 + X1 + Z1 );
    driveLB.move( Y1 - X1 + Z1 );
    driveRF.move( Y1 - X1 - Z1 );
    driveRB.move( Y1 + X1 - Z1 );

    if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
      intakeMtr.move(127);
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)){
      intakeMtr.move(-127);
    }
    else {
      intakeMtr.move(0);
    }




/*
  
    
    if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
     punchMtrL.move(127);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)){
      punchMtrL.move_absolute(250, 200);
      
    }
    else {
      punchMtrL.move(0);
    }*/
 
    if((master.get_digital(E_CONTROLLER_DIGITAL_X))){
      yeetMtr.move(-200);
    }
    else if ((master.get_digital(E_CONTROLLER_DIGITAL_B))){
      yeetMtr.move(200);
    }
    else{
      yeetMtr.move(0);
    }



    if ((master.get_digital(E_CONTROLLER_DIGITAL_X)) && (master.get_digital(E_CONTROLLER_DIGITAL_B))){
      angleMtr.tare_position();
    }

    if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
      angle = 50;
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_UP)){
      angle = 0;
    }
    else {}
      angleMtr.move_absolute(angle, 50);

		pros::delay(20);
	}
}
