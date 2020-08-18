#include "main.h"
#include "display.h"
#include "chassis.h"
//Device initialize
///Controller
Controller master(CONTROLLER_MASTER);
///DRIVE
Motor driveLF(13/*Port*/, E_MOTOR_GEARSET_18/*Gearset(red/blue/green)*/, false/*motor reversed?*/, E_MOTOR_ENCODER_DEGREES/*set encoder units to be used*/);
Motor driveLB(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor driveRF(12, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor driveRB(2, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
///ADI
ADILineSensor intakeSensor('a');
ADIUltrasonic backR ('3', '4');
ADIUltrasonic backL ('5', '6');

Chassis drivef;
Display cinema;

int SelectedAuto;

void initialize() {
	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	cinema.createScreen();
	cinema.refresh();
}

void disabled() {}


void competition_initialize() {}


void autonomous() {}

void opcontrol() {


	while (true) {
		drivef.operator_Chassis();
		cinema.refresh();
		pros::delay(20);
	}
}
