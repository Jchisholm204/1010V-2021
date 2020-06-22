#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "pros/apix.h"
#include "okapi/api.hpp"
#include "chassis.h"
//#include "display.h"
//#include "pros/api_legacy.h"
 using namespace pros;
// using namespace pros::literals;
// using namespace okapi;
//Classes
extern Chassis drivef;
//Controllers
extern Controller master;

//Motors
///Intakes
///Drive
extern Motor driveFR;
extern Motor driveFL;
extern Motor driveBR;
extern Motor driveBL;

//Modes
#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT -1
#define DIRECTION_BACK 1
#define DIRECTION_FORWARD -1

//ADI
///Sensors
extern ADILineSensor intakeSensor;
extern ADIUltrasonic backR;
extern ADIUltrasonic backL;
/*
WIRING ADIUltrasonic:
port_ping	the port connected to the orange OUTPUT cable. This should be in port 1, 3, 5, or 7 (‘A’, ‘C’, ‘E’, ‘G’).
port_echo	the port connected to the yellow INPUT cable. This should be in the next highest port following port_ping.
*/
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
