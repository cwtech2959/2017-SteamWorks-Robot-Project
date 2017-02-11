/*
 * GearDropOffCommand.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#include <Commands/GearDropOffCommand.h>

GearDropOffCommand::GearDropOffCommand(bool open) :
		CommandBase("GearDropOffCommand")
{
	Requires(GearManagementSubsystem.get());
	m_open = open;
}

GearDropOffCommand::~GearDropOffCommand()
{
}

void GearDropOffCommand::Initialize()
{
	GearManagementSubsystem->StartGearDropOffMotors(m_open);
	int time = GearManagementSubsystem->GetGearGateTime();

	SetTimeout(time * 0.001);
}

bool GearDropOffCommand::IsFinished()
{
	return IsTimedOut();
}

void GearDropOffCommand::End()
{
	GearManagementSubsystem->StopGearDropOffMotors();
}

void GearDropOffCommand::Interrupted()
{
	End();
}
