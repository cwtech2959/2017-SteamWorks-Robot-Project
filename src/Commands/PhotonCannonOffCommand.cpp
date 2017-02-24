/*
 * PhotonCannonCommand2.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Kevin
 */

#include <Commands/PhotonCannonOffCommand.h>
#include <Robot.h>

PhotonCannonOffCommand::PhotonCannonOffCommand()
{
}

PhotonCannonOffCommand::~PhotonCannonOffCommand()
{
}

void PhotonCannonOffCommand::Execute()
{
	Robot::PhotonCannonSubsystem->LightOff();
}

bool PhotonCannonOffCommand::IsFinished()
{
	return true;
}
