/*
 * Climb.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Subsystems/RopeClimb.h>
#include "RobotMap.h"

RopeClimb::RopeClimb() : Subsystem("Climb")
{
	ClimbMotor.reset(new Spark(CLIMB_PWM));
}

RopeClimb::~RopeClimb()
{
}
