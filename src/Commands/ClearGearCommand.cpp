/*
 * ClearGearCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/ClearGearCommand.h>
#include <Robot.h>

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
	Robot::LoaderSubsystem->ReverseLoaderConveyor();
}

void ClearGearCommand::Execute()
{
	if (m_gearGone == false && Robot::GearLoadSubsystem->GetGearLoadReady() == false)
	{
		SetTimeout(0.5);
		m_gearGone = true;
	}
}

bool ClearGearCommand::IsFinished()
{
	return m_gearGone && IsTimedOut();
}

void ClearGearCommand::End()
{
	Robot::LoaderSubsystem->LoaderConveyorForward();
}

void ClearGearCommand::Interrupted()
{
	End();
}
