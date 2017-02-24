/*
 * FryingPanUpCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/FryingPanUpCommand.h>
#include <Robot.h>

FryingPanUpCommand::FryingPanUpCommand(bool up) :
		Command("FryingPanUpCommand")
{
	Requires(Robot::GearManagementSubsystem.get());
	m_up = up;
}

FryingPanUpCommand::~FryingPanUpCommand()
{
}

void FryingPanUpCommand::Initialize()
{
	Robot::GearManagementSubsystem->StartFryingPanMotor(m_up);

	int time = Robot::GearManagementSubsystem->GetFryingPanStallTime();
	SetTimeout(time * 0.001);
}

bool FryingPanUpCommand::IsFinished()
{
	if (m_up)
	{
		return IsTimedOut() || Robot::GearManagementSubsystem->GetFryingPanUpSwitch();
	}
	else
	{
		return IsTimedOut() || Robot::GearManagementSubsystem->GetFryingPanDownSwitch();
	}
}

void FryingPanUpCommand::End()
{
	Robot::GearManagementSubsystem->StopFryingPanMotor();
}

void FryingPanUpCommand::Interrupted()
{
	End();
}
