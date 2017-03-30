/*
 * DriveStraight.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#include <Commands/DriveStraightCommand.h>
#include <Robot.h>

DriveStraightCommand::DriveStraightCommand() :
	Command("DriveStraightCommand")
{
}

DriveStraightCommand::~DriveStraightCommand()
{
}

void DriveStraightCommand::Initialize()
{
	Robot::DriveTrainSubsystem->SetDriveStraight(true);
}

bool DriveStraightCommand::IsFinished()
{
	return false;
}

void DriveStraightCommand::End()
{
	Robot::DriveTrainSubsystem->SetDriveStraight(false);
}

void DriveStraightCommand::Interrupted()
{
	End();
}
