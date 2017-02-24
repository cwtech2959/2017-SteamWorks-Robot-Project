/*
 * TogglePhotonCannonCommand.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#include <Commands/PhotonCannonOnCommand.h>
#include <Robot.h>

PhotonCannonOnCommand::PhotonCannonOnCommand() :
	Command("PhotonCannonCommand")
{
	Requires(Robot::PhotonCannonSubsystem.get());
}

PhotonCannonOnCommand::~PhotonCannonOnCommand()
{
}

void PhotonCannonOnCommand::Execute()
{
	Robot::PhotonCannonSubsystem->LightOn();
}

bool PhotonCannonOnCommand::IsFinished()
{
	return true;
}
