#include "main.h"
using namespace okapi;

void opcontrol() {

  pros::Task::delay(100);

  //Arm
  Motor armMotorL = 3_rmtr; //Arm Motor Left
  Motor armMotorR = 8_rmtr; //Arm Motor Right

  //Drive
  auto drive = ChassisControllerFactory::create (
                 {driveLF, driveLB}, {driveRF, driveRB}, //Left Ports + Right Ports
                 AbstractMotor::gearset::green, //Motor Gear Ration
                 {3.25_in, 12.5_in} //Wheel Diameter + Base Width
               );
  auto profileController = AsyncControllerFactory::motionProfile (1.0/*Velocity*/, 2.0/*Acceleration*/, 9.0/*Jerk*/, drive);

  //Sensors
  Controller controller; //Set Main Controller
  ControllerButton armUpButton(ControllerDigital::A); //Button A
  ControllerButton armDownButton(ControllerDigital::B); //Button B
  ControllerButton runAutoButton(ControllerDigital::X); //Button X

  const int intakeMotor = 5;
  const double liftkP = 2.5;
  const double liftkI = 0;
  const double liftkD = 0;
  auto intakeController = AsyncControllerFactory::posPID(intakeMotor, liftkP, liftkI, liftkD);

	profileController.generatePath({
  	Point{0_ft, 0_ft, 0_deg},
  	Point{1_ft, -2_ft, -90_deg}},
  	"MEMES"
	);

  while (true) {

    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),
                 controller.getAnalog(ControllerAnalog::rightX));

    if (armUpButton.isPressed()) {
      armMotorL.move_voltage(127);
      armMotorR.move_voltage(127);
    } else if (armDownButton.isPressed()) {
      armMotorL.move_voltage(-127);
      armMotorR.move_voltage(-127);
    } else {
      armMotorL.move_voltage(0);
      armMotorR.move_voltage(0);
    }

    if (runAutoButton.changedToPressed()) {
      intakeController.setTarget(200);
    }

    pros::Task::delay(10);

  }
}
