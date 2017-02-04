/*
 * ReverseFireCommand.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#include <Commands/ReverseFireCommand.h>
#include <Subsystems/ShooterAndLoader.h>

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
	if (ShooterAndLoaderSubsystem->GetShooting() == false)
	{
		ShooterAndLoaderSubsystem->ReverseShooterConveyors();
	}
}

bool ReverseFireCommand::IsFinished()
{
	return false;
}

void ReverseFireCommand::End()
{
	if (ShooterAndLoaderSubsystem->GetShooting() == false)
	{
		ShooterAndLoaderSubsystem->ShooterConveyorsOff();
	}
}

void ReverseFireCommand::Interrupted()
{
	End();
}
