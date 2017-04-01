/*
 * ClimbWithJoystick.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author:
 */

#include <Commands/ClimbWithJoystick.h>
#include <Robot.h>

ClimbWithJoystick::ClimbWithJoystick() : Command("ClimbWithJoystick")
{
	Requires(Robot::ClimbSubsystem.get());
}

ClimbWithJoystick::~ClimbWithJoystick()
{
}

void ClimbWithJoystick::Execute()
{
	Robot::ClimbSubsystem->Climb(Robot::oi->GetClimbJoystick());
}

bool ClimbWithJoystick::IsFinished()
{
	return false;
}
