/*
 * ReverseFireCommand.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#include <Commands/ReverseFireCommand.h>
#include <Subsystems/Shooter.h>
#include <Robot.h>

ReverseFireCommand::ReverseFireCommand() :
		Command("ReverseFireCommand")
{
	Requires(Robot::ShooterSubsystem.get());
}

ReverseFireCommand::~ReverseFireCommand()
{
}

void ReverseFireCommand::Execute()
{
	if (Robot::ShooterSubsystem->GetShooting() == false)
	{
		Robot::ShooterSubsystem->ReverseShooterConveyors();
	}
}

bool ReverseFireCommand::IsFinished()
{
	return false;
}

void ReverseFireCommand::End()
{
	if (Robot::ShooterSubsystem->GetShooting() == false)
	{
		Robot::ShooterSubsystem->ShooterConveyorsOff();
	}
}

void ReverseFireCommand::Interrupted()
{
	End();
}
