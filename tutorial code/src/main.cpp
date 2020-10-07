#include "main.h"
void initialize() {

}

void disabled() {}

void competition_initialize() {}


void autonomous() {}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);
	pros::Motor rightback(4);

	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;
		rightback = right;

		rightback.move_velocity(100);
		rightback.move_voltage(-127);

		pros::delay(20);
	}
}
