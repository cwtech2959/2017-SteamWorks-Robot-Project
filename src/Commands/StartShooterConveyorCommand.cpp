/*
 * StartShootConveyor.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/StartShooterConveyorCommand.h>

StartShooterConveyorCommand::StartShooterConveyorCommand(Shooter::ShooterSide side) :
		CommandBase("StartShootConveyorCommand")
{
	Requires(ShooterSubsystem.get());

	m_shooterSide = side;
}

StartShooterConveyorCommand::~StartShooterConveyorCommand()
{
}

void StartShooterConveyorCommand::Initialize()
{
	SetTimeout(ShooterSubsystem->GetOnTime() * 0.001);
	ShooterSubsystem->ShooterConveyorOn(m_shooterSide);
}

bool StartShooterConveyorCommand::IsFinished()
{
	return IsTimedOut();
}

void StartShooterConveyorCommand::End()
{
	ShooterSubsystem->ShooterConveyorOff(m_shooterSide);
}

void StartShooterConveyorCommand::Interrupted()
{
	End();
}
