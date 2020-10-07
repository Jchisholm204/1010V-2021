#include "main.h"
#include "chassis.h"

int exponential (int joystickVal, float driveExp, int joyDead, int motorMin) { //exponential incrementation of joystick values
		   	int joySign;
		    int joyMax = 128 - joyDead;
		    int joyLive = abs(joystickVal) - joyDead;
		    if (joystickVal > 0) {joySign = 1;}
		    else if (joystickVal < 0) {joySign = -1;}
		    else {joySign = 0;}
		    int power = joySign * (motorMin + ((127 - motorMin) * (pow(joyLive, driveExp) / pow(joyMax, driveExp))));
		    return power;
}
void Chassis::operator_Chassis(void){
  int Y1 = exponential(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y), 1.5 /*DriveExp*/, 8 /*JoyDead*/, 15 /*MotorMin*/);
	int X1 = exponential(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X), 1.5 /*DriveExp*/, 8 /*JoyDead*/, 15 /*MotorMin*/);
	int Z1 = exponential(master.get_analog(E_CONTROLLER_ANALOG_LEFT_X), 1.5 /*DriveExp*/, 8 /*JoyDead*/, 15 /*MotorMin*/);
	//int E2 = exponential(partner.get_analog(E_CONTROLLER_ANALOG_LEFT_X), 1.5 /*DriveExp*/, 8 /*JoyDead*/, 15 /*MotorMin*/);
	//Expo drive outputs
	int FL = ( Y1 + X1 + Z1 );  //map LF to left y, right X
	int BL = ( Y1 + X1 - Z1 );  //map LB to left y, right X
	int FR = ( Y1 - X1 - Z1 );  //map RF to left y, right X
	int BR = ( Y1 - X1 + Z1 );  //map RB to left y, right X
	//Motor Outputs
	driveBL.move(BL);
	driveFL.move(FL);
	driveBR.move(BR);
	driveFR.move(FL);
}
void Chassis::stopDriving(void){
	//all drive motors stop
	driveBL.move(0);
	driveFL.move(0);
	driveBR.move(0);
	driveFR.move(0);
}
void Chassis::timeDrive(int time, int velocity){
	//drive motors move velocity [Green = 200rpm min/max]
	driveBL.move_velocity(velocity);
	driveFL.move_velocity(velocity);
	driveBR.move_velocity(velocity);
	driveFR.move_velocity(velocity);
	pros::delay(time); //delay
	//all drive motors stop
  driveBL.move(0);
	driveFL.move(0);
	driveBR.move(0);
	driveBR.move(0);
}
void Chassis::timeGlide(int time, int velocity){
	//drive motors move velocity [Green = 200rpm min/max]
	driveBL.move_velocity(-velocity);
	driveFL.move_velocity(velocity);
	driveBR.move_velocity(velocity);
	driveFR.move_velocity(-velocity);
	pros::delay(time); //delay
	//all drive motors stop
  driveBL.move(0);
	driveFL.move(0);
	driveBR.move(0);
	driveBR.move(0);
}
void Chassis::TurnDistance(int direction, int targetValue, int timeout){
		float driveKP = 1.2;
		float driveKD = 0.8;
		int motorPower; //motor power level
		int startTime = millis(); //Elapsed time since start of the sequence
		int currentValue = 0; //starting value of 0
		int turn_err = 0; //error value init
		int derr = 0;//error difference
		int err_last = 0; //last error
		int err_sum = 0; //sum of errors
		float KI = 0; //KI value - not currently used'
		float p; //p value normally 0.8
		float i = 0; //I value
		float d; //d value normally 0.7
		driveBL.tare_position();
		driveBR.tare_position();
		while((millis() - startTime) < timeout){
			//reset motor encoders
			if(direction == DIRECTION_RIGHT){  //left encoder if turing right
				currentValue = driveBL.get_position();
			}
			else if(direction == DIRECTION_LEFT){  // right encoder if turing left
				currentValue = driveBR.get_position();
			}
			turn_err = targetValue - currentValue;
			err_last = turn_err;
			derr = (turn_err - err_last);
			p = (driveKP * turn_err);
			err_sum += turn_err;
			d = driveKD * derr;

			motorPower = p+i+d; //motorpower is the sum of p, i, and d

			if(motorPower > 50){motorPower = 50;} //if the motor power is greater than 127 (the maximun it can go), set it to 127
			if(motorPower < -50){motorPower = -50;}//if the motor power is less than -127 (the minimum it can go), set it to -127

				driveFR.move(direction*motorPower);
				driveBL.move((-direction*motorPower));
				driveBR.move((direction*motorPower));
				driveFL.move(-direction*motorPower);
			delay(20);
		}
}
void Chassis::MoveDistance(int direction, int targetValue, int timeout){
	float driveKP = 1.2;
	float driveKD = 0.8;
	int motorPower; //motor power level
	int startTime = millis(); //Elapsed time since start of the sequence
	int currentValue = 0; //starting value of 0
	int turn_err = 0; //error value init
	int derr = 0;//error difference
	int err_last = 0; //last error
	int err_sum = 0; //sum of errors
	float KI = 0; //KI value - not currently used'
	float p; //p value normally 0.8
	float i = 0; //I value
	float d; //d value normally 0.7
	driveBR.tare_position();
	driveBL.tare_position();
	while((millis() - startTime) < timeout){
		currentValue = (driveBR.get_position() + driveBL.get_position()) /2;
		turn_err = targetValue - currentValue;
		err_last = turn_err;
		derr = (turn_err - err_last);
		p = (driveKP * turn_err);
		err_sum += turn_err;
		d = driveKD * derr;

		motorPower = p+i+d; //motorpower is the sum of p, i, and d

		if(motorPower > 85){motorPower = 85;}
		if(motorPower < -85){motorPower = -85;}

			driveFR.move(direction*motorPower);
      driveBL.move((direction*motorPower));
      driveBR.move((direction*motorPower));
      driveFL.move(direction*motorPower);
		delay(20);
	}
}
void Chassis::MoveSlow(int direction, int targetValue, int timeout){
  float driveKP = 1.2;
  float driveKD = 0.8;
  int motorPower; //motor power level
  int startTime = millis(); //Elapsed time since start of the sequence
  int currentValue = 0; //starting value of 0
  int turn_err = 0; //error value init
  int derr = 0;//error difference
  int err_last = 0; //last error
  int err_sum = 0; //sum of errors
  float KI = 0; //KI value - not currently used'
  float p; //p value normally 0.8
  float i = 0; //I value
  float d; //d value normally 0.7
  driveBR.tare_position();
  driveBL.tare_position();
  while((millis() - startTime) < timeout){
    currentValue = (driveBR.get_position() + driveBL.get_position()) /2;
    turn_err = targetValue - currentValue;
    err_last = turn_err;
    derr = (turn_err - err_last);
    p = (driveKP * turn_err);
    err_sum += turn_err;
    d = driveKD * derr;

    motorPower = p+i+d; //motorpower is the sum of p, i, and d

    if(motorPower > 70){motorPower = 70;} //if the motor power is greater than 127 (the maximun it can go), set it to 127
    if(motorPower < -70){motorPower = -70;}//if the motor power is less than -127 (the minimum it can go), set it to -127

      driveFL.move(direction*motorPower);
      driveBL.move((direction*motorPower));
      driveBR.move((direction*motorPower));
      driveFL.move(direction*motorPower);
    delay(20);
  }
}
