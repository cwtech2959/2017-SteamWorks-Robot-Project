/*
 * GearDropOffCommand.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#include <Commands/GearDropOffCommand.h>

GearDropOffCommand::GearDropOffCommand() :
		CommandBase("GearDropOffCommand")
{
	Requires(GearManagementSubsystem.get());

}
GearDropOffCommand::~GearDropOffCommand()
{
}

void GearDropOffCommand::Initialize()
{
	GearManagementSubsystem->StartGearDropOffMotors(true);

	SetTimeout(.5);
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
