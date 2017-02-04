/*
 * ReverseFireCommand.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#include <Commands/ReverseFireCommand.h>

ReverseFireCommand::ReverseFireCommand() :
		CommandBase("ReverseFireCommand")
{
	Requires(ShooterAndLoaderSubsystem.get());
}

ReverseFireCommand::~ReverseFireCommand()
{
}

void ReverseFireCommand::Execute()
{
	ShooterAndLoaderSubsystem->ReverseShooterConveyors();
}

bool ReverseFireCommand::IsFinished()
{
	return false;
}

void ReverseFireCommand::End()
{
	ShooterAndLoaderSubsystem->ShooterConveyorsOff();
}

void ReverseFireCommand::Interrupted()
{
	End();
}
