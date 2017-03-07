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
	int time = Robot::GearManagementSubsystem->GetGearGateTime();
	SetTimeout(SecondsFromMilliSeconds(time));
}

void GearDropOffCommand::Execute()
{
	Robot::GearManagementSubsystem->MoveGearDropOff(m_open, ramp.NextSpeed(Robot::GearManagementSubsystem->GetGearReleaseDriveSpeed()));
}

bool GearDropOffCommand::IsFinished()
{
	return IsTimedOut();
}

void GearDropOffCommand::End()
{
	Robot::GearManagementSubsystem->MoveGearDropOff(m_open, ramp.NextSpeed(0));
}

void GearDropOffCommand::Interrupted()
{
	End();
}
