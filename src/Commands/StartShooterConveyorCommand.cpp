/*
 * StartShootConveyor.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/StartShooterConveyorCommand.h>
#include <Robot.h>

StartShooterConveyorCommand::StartShooterConveyorCommand(Shooter::ShooterSide side) :
		Command("StartShootConveyorCommand")
{
	Requires(Robot::ShooterSubsystem.get());

	m_shooterSide = side;
}

StartShooterConveyorCommand::~StartShooterConveyorCommand()
{
}

void StartShooterConveyorCommand::Initialize()
{
	SetTimeout(Robot::ShooterSubsystem->GetOnTime() * 0.001);
	Robot::ShooterSubsystem->ShooterConveyorOn(m_shooterSide);
}

bool StartShooterConveyorCommand::IsFinished()
{
	return IsTimedOut();
}

void StartShooterConveyorCommand::End()
{
	Robot::ShooterSubsystem->ShooterConveyorOff(m_shooterSide);
}

void StartShooterConveyorCommand::Interrupted()
{
	End();
}
