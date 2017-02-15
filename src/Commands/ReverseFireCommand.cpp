/*
 * ReverseFireCommand.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#include <Commands/ReverseFireCommand.h>
#include <Subsystems/Shooter.h>

ReverseFireCommand::ReverseFireCommand() :
		CommandBase("ReverseFireCommand")
{
	Requires(ShooterSubsystem.get());
}

ReverseFireCommand::~ReverseFireCommand()
{
}

void ReverseFireCommand::Execute()
{
	if (ShooterSubsystem->GetShooting() == false)
	{
		ShooterSubsystem->ReverseShooterConveyors();
	}
}

bool ReverseFireCommand::IsFinished()
{
	return false;
}

void ReverseFireCommand::End()
{
	if (ShooterSubsystem->GetShooting() == false)
	{
		ShooterSubsystem->ShooterConveyorsOff();
	}
}

void ReverseFireCommand::Interrupted()
{
	End();
}
