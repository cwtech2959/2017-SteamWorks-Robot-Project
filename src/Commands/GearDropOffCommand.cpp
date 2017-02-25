/*
 * GearDropOffCommand.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#include <Commands/GearDropOffCommand.h>
#include <Robot.h>
#include <Utilities.h>

GearDropOffCommand::GearDropOffCommand(bool open) :
		Command("GearDropOffCommand")
{
	Requires(Robot::GearManagementSubsystem.get());
	m_open = open;
}

GearDropOffCommand::~GearDropOffCommand()
{
}

void GearDropOffCommand::Initialize()
{
	Robot::GearManagementSubsystem->StartGearDropOffMotors(m_open);

	int time = Robot::GearManagementSubsystem->GetGearGateTime();
	SetTimeout(SecondsFromMilliSeconds(time));
}

bool GearDropOffCommand::IsFinished()
{
	return IsTimedOut();
}

void GearDropOffCommand::End()
{
	Robot::GearManagementSubsystem->StopGearDropOffMotors();
}

void GearDropOffCommand::Interrupted()
{
	End();
}
