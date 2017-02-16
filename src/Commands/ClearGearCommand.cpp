/*
 * ClearGearCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/ClearGearCommand.h>

ClearGearCommand::ClearGearCommand() :
	CommandBase("ClearGearCommand")
{
	Requires(LoaderSubsystem.get());
	m_gearGone = false;
}

ClearGearCommand::~ClearGearCommand()
{
}

void ClearGearCommand::Initialize()
{
	LoaderSubsystem->ReverseLoaderConveyor();
}

void ClearGearCommand::Execute()
{
	if (m_gearGone == false && GearManagementSubsystem->GearLoadReady.Get() == false)
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
	LoaderSubsystem->LoaderConveyorForward();
}

void ClearGearCommand::Interrupted()
{
	End();
}
