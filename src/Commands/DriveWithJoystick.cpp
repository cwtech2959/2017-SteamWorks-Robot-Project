/*
 * DriveWithJoystick.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#include <Commands/DriveWithJoystick.h>
#include <Robot.h>

DriveWithJoystick::DriveWithJoystick() : Command("DriveWithJoystick")
{
	Requires(Robot::DriveTrainSubsystem.get());
}

DriveWithJoystick::~DriveWithJoystick()
{
}

void DriveWithJoystick::Execute()
{
	Robot::DriveTrainSubsystem->TankDrive(Robot::oi->GetDriverJoystick());
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
