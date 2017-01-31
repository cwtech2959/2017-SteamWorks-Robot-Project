/*
 * PhotonCannonCommand2.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Kevin
 */

#include <Commands/PhotonCannonOffCommand.h>

PhotonCannonOffCommand::PhotonCannonOffCommand()
{
	// TODO Auto-generated constructor stub

}

PhotonCannonOffCommand::~PhotonCannonOffCommand()
{
	// TODO Auto-generated destructor stub
}

void PhotonCannonOffCommand::Execute()
{
	myPhotonCannonSubsystem->LightOff();
}

bool PhotonCannonOffCommand::IsFinished()
{
	return true;
}
