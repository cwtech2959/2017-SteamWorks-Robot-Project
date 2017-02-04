/*
 * StartShootConveyor.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/StartShooterConveyorCommand.h>

StartShooterConveyorCommand::StartShooterConveyorCommand(ShooterAndLoader::ShooterSide side) :
		CommandBase("StartShootConveyorCommand")
{
	Requires(ShooterAndLoaderSubsystem.get());

	m_shooterSide = side;
}

StartShooterConveyorCommand::~StartShooterConveyorCommand()
{
}

void StartShooterConveyorCommand::Initialize()
{
	SetTimeout(ShooterAndLoaderSubsystem->GetOnTime() * 0.001);
	ShooterAndLoaderSubsystem->ShooterConveyorOn(m_shooterSide);
}

bool StartShooterConveyorCommand::IsFinished()
{
	return IsTimedOut();
}

void StartShooterConveyorCommand::End()
{
	ShooterAndLoaderSubsystem->ShooterConveyorOff(m_shooterSide);
}

void StartShooterConveyorCommand::Interrupted()
{
	End();
}
