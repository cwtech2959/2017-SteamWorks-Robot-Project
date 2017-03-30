/*
 * InvertTankCommand.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#include <Commands/InvertTankCommand.h>
#include <Robot.h>

InvertTankCommand::InvertTankCommand() :
	Command("InvertTankCommand")
{
}

InvertTankCommand::~InvertTankCommand()
{
}

void InvertTankCommand::Initialize()
{
	Robot::DriveTrainSubsystem->SetInvertTank(true);
}

bool InvertTankCommand::IsFinished()
{
	return false;
}

void InvertTankCommand::End()
{
	Robot::DriveTrainSubsystem->SetInvertTank(false);
}

void InvertTankCommand::Interrupted()
{
	End();
}
