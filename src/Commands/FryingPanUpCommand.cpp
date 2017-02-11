/*
 * FryingPanUpCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/FryingPanUpCommand.h>

FryingPanUpCommand::FryingPanUpCommand(bool up) :
		CommandBase("FryingPanUpCommand")
{
	Requires(GearManagementSubsystem.get());
	m_up = up;
}

FryingPanUpCommand::~FryingPanUpCommand()
{
}

void FryingPanUpCommand::Initialize()
{
	GearManagementSubsystem->StartFryingPanMotor(m_up);

	int time = GearManagementSubsystem->GetFryingPanStallTime();
	SetTimeout(time * 0.001);
}

bool FryingPanUpCommand::IsFinished()
{
	if (m_up)
	{
		return IsTimedOut() || GearManagementSubsystem->GetFryingPanUpSwitch();
	}
	else
	{
		return IsTimedOut() || GearManagementSubsystem->GetFryingPanDownSwitch();
	}
}

void FryingPanUpCommand::End()
{
	GearManagementSubsystem->StopFryingPanMotor();
}

void FryingPanUpCommand::Interrupted()
{
	End();
}
