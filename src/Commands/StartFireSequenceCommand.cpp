/*
 * StartFireSequenceCommand.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#include <Commands/StartFireSequenceCommand.h>

StartFireSequenceCommand::StartFireSequenceCommand() :
	CommandBase("StartFireSequenceCommand")
{
	Requires(ShooterAndLoaderSubsystem.get());
}

StartFireSequenceCommand::~StartFireSequenceCommand()
{
}

void StartFireSequenceCommand::Execute()
{
	ShooterAndLoaderSubsystem->StartShooterConveyors();
}

bool StartFireSequenceCommand::IsFinished()
{
	return false;
}

void StartFireSequenceCommand::End()
{
	ShooterAndLoaderSubsystem->ShooterConveyorsOff();
}

void StartFireSequenceCommand::Interrupted()
{
	End();
}
