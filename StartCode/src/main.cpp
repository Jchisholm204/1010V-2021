#include "main.h"

//Device initialize
///Controller
Controller master(CONTROLLER_MASTER);
///DRIVE
Motor driveLF(1/*Port*/, E_MOTOR_GEARSET_18/*Gearset(red/blue/green)*/, false/*motor reversed?*/, E_MOTOR_ENCODER_DEGREES/*set encoder units to be used*/);
Motor driveLB(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveRF(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
///Motors
Motor intakeFL(5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);
Motor intakeFR(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);
Motor intake(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_ROTATIONS);
///ADI
ADILineSensor intakeSensor('a');
ADIUltrasonic backR ('3', '4');
ADIUltrasonic backL ('5', '6');



void initialize() {
	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	intakeFR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	intakeFL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	intake.set_brake_mode(E_MOTOR_BRAKE_BRAKE);

}

void disabled() {}


void competition_initialize() {}


void autonomous() {}

void opcontrol() {


	while (true) {

		pros::delay(20);
	}
}
