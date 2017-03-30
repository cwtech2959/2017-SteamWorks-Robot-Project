/*
 * PowerReduceCommand.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#include <Commands/PowerReduceCommand.h>
#include <Robot.h>

PowerReduceCommand::PowerReduceCommand() :
	Command("PowerReduceCommand")
{
}

PowerReduceCommand::~PowerReduceCommand()
{
}

void PowerReduceCommand::Initialize()
{
	Robot::DriveTrainSubsystem->SetPowerReduction(true);
}

bool PowerReduceCommand::IsFinished()
{
	return false;
}

void PowerReduceCommand::End()
{
	Robot::DriveTrainSubsystem->SetPowerReduction(false);
}

void PowerReduceCommand::Interrupted()
{
	End();
}
