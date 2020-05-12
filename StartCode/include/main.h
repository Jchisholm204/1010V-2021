/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"


//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"


 using namespace pros;
// using namespace pros::literals;
// using namespace okapi;
//Controllers
extern Controller master;

//Motors
///Intakes
extern Motor intakeFL;
extern Motor intakeFR;
extern Motor intake;
///Drive
extern Motor driveFR;
extern Motor driveFL;
extern Motor driveBR;
extern Motor driveBL;


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

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
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
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
