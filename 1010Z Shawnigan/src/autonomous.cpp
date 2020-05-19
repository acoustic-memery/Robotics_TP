#include "main.h"

void encWipe(){
    driveLF.tare_position();
    driveLB.tare_position();
    driveRB.tare_position();
    driveRF.tare_position();
  //  punchMtrR.tare_position();
    punchMtrL.tare_position();
    intakeMtr.tare_position();
    angleMtr.tare_position();
}

void driveWipe(){
     driveLF.tare_position();
    driveLB.tare_position();
    driveRB.tare_position();
    driveRF.tare_position();
}



void driveForeward(int amount, int speed){
driveWipe();
driveLB.move_absolute(amount, speed);
driveLF.move_absolute(amount, speed);
driveRB.move_absolute(amount, speed);
driveRF.move_absolute(amount, speed);

 while(abs(driveLB.get_position()) < amount){
       pros::lcd::print(1, "drive foreward");
        pros::delay(2);
    }

}

void driveBack(int amount, int speed){
driveWipe();
driveLB.move_absolute(-amount, -speed);
driveLF.move_absolute(-amount, -speed);
driveRB.move_absolute(-amount, -speed);
driveRF.move_absolute(-amount, -speed);

 while(abs(driveLB.get_position()) < amount){
       pros::lcd::print(1, "drive back");
        pros::delay(2);
    }

}

void driveRight(int amount, int speed){
    
driveWipe();
driveLB.move_absolute(amount, speed);
driveLF.move_absolute(amount, speed);
driveRB.move_absolute(-amount, -speed);
driveRF.move_absolute(-amount, -speed);

 while(abs(driveRB.get_position()) < amount){
       pros::lcd::print(1, "turn right");
        pros::delay(2);
    }

}

void driveLeft(int amount, int speed){
driveWipe();
driveLB.move_absolute(-amount, -speed);
driveLF.move_absolute(-amount, -speed);
driveRB.move_absolute(amount, speed);
driveRF.move_absolute(amount, speed);

 while(abs(driveRF.get_position()) < amount){
       pros::lcd::print(1, "turn Left");
        pros::delay(2);
    }

}

void timeRight(int timeout, int speed){
driveWipe();
driveLB.move( -speed);
driveLF.move(speed);
driveRB.move( speed);
driveRF.move( -speed);
pros::delay(timeout);
driveLB.move( 0);
driveLF.move(0);
driveRB.move( 0);
driveRF.move( 0);

}

void strafeLeft(int amount, int speed){
driveWipe();
driveLB.move_absolute(amount, speed);
driveLF.move_absolute(-amount, -speed);
driveRB.move_absolute(-amount, -speed);
driveRF.move_absolute(amount, speed);

 while(abs(driveLB.get_position()) < amount){
       pros::lcd::print(1, "strafe left");
        pros::delay(2);
    }

}

void strafeRight(int amount, int speed){
driveWipe();
driveLB.move_absolute(-amount, -speed);
driveLF.move_absolute(amount, speed);
driveRB.move_absolute(amount, speed);
driveRF.move_absolute(-amount, -speed);

 while(abs(driveLB.get_position()) < amount){
       pros::lcd::print(1, "strafe right");
        pros::delay(2);
    }

}

void aimShot(int amount, int speed){
    angleMtr.move_absolute(amount, speed);

}

void shootBall(int amount){
    punchMtrL.move_absolute(amount, 127);
 //  punchMtrR.move_absolute(amount, 127);
}

void smartIntake(){
    while(lightSensor.get_value() > 2500){
        intakeMtr.move_velocity(200);
        if(lightSensor.get_value() < 2500){
            break;
        }
    }
    intakeMtr.move_velocity(0);
}

void blueFlags(){
     encWipe();
    driveForeward(900, 150);
    intakeMtr.move(127);
pros::delay(250);
    driveForeward(275, 100);
    intakeMtr.move(0);
    driveBack(1075,150);
    encWipe();
    driveRight(520, 120);
    delay(200);
     intakeMtr.move(-200);
    delay(100);
    intakeMtr.move(0);
    smartIntake();
    delay(100);
    shootBall(400);
    delay(1200);
   aimShot(100, 127);
   smartIntake();
    delay(100);
    encWipe();
    shootBall(400);
    delay(1000);
    aimShot(-100, -127);
   // driveForeward(900, 200);


    strafeLeft(1025,  200);
     delay(200);
    driveForeward(100,200);
 delay(200); delay(200);
    driveBack(1200, 200);

}

void redFlags(){
  encWipe();
  punchMtrL.move_absolute(200, 200);
    driveForeward(900, 150);
    intakeMtr.move(127);
pros::delay(250);
    driveForeward(300, 100);
    intakeMtr.move(0);
    driveBack(1175,150);
    driveLeft(520, 120);
   delay(200);
     intakeMtr.move(-200);
    delay(100);
    intakeMtr.move(0);
    smartIntake();
    delay(100);
    shootBall(400);
    delay(1200);
   aimShot(50, 127);
   punchMtrL.move_absolute(210, 200);
   smartIntake();
    delay(100);
    encWipe();
    shootBall(400);
    delay(1000);
    aimShot(-100, -127);
   // driveForeward(900, 200);


    strafeRight(1025,  200);
    delay(200);
    driveForeward(100, 200);
     delay(200);
   
    driveBack(1000, 200);

}

void redBack(){

    encWipe();
    driveForeward(900, 150);
    intakeMtr.move(127);
pros::delay(250);
    driveForeward(275, 100);
    intakeMtr.move(0);
    driveBack(240, 150);
    driveRight(520, 110);
    encWipe();
     driveBack(1000, 200);
}

void blueBack(){

    encWipe();
    driveForeward(900, 150);
    intakeMtr.move(127);
pros::delay(250);
    driveForeward(275, 100);
    intakeMtr.move(0);
    driveBack(240, 150);
    encWipe();
    driveLeft(520, 110);
    encWipe();
     driveBack(1000, 200);
}

void autonomous() {
   
redBack();

}
