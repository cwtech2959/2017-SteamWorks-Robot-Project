/*
 * ClearGearCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/ClearGearCommand.h>
#include <Robot.h>
#include <Utilities.h>

ClearGearCommand::ClearGearCommand() :
	Command("ClearGearCommand")
{
	Requires(Robot::LoaderSubsystem.get());
	m_gearGone = false;
}

ClearGearCommand::~ClearGearCommand()
{
}

void ClearGearCommand::Initialize()
{
	Robot::LoaderSubsystem->ReverseBallLoader();
}

void ClearGearCommand::Execute()
{
	if (m_gearGone == false && Robot::GearLoadSubsystem->GetGearLoadReady() == false)
	{
		SetTimeout(SecondsFromMilliSeconds(Robot::LoaderSubsystem->GetGearClearTime()));
		m_gearGone = true;
	}
}

bool ClearGearCommand::IsFinished()
{
	return m_gearGone && IsTimedOut();
}

void ClearGearCommand::End()
{
	Robot::LoaderSubsystem->BallLoaderForward();
}

void ClearGearCommand::Interrupted()
{
	End();
}
