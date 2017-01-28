/*
 * TogglePhotonCannonCommand.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#include <Commands/PhotonCannonCommand.h>

PhotonCannonCommand::PhotonCannonCommand() :
	CommandBase("PhotonCannonCommand")
{
	// TODO Auto-generated constructor stub
	Requires(myPhotonCannonSubsystem.get());

}

PhotonCannonCommand::~PhotonCannonCommand() {
	// TODO Auto-generated destructor stub
}

void PhotonCannonCommand::Execute()
{
	myPhotonCannonSubsystem->LightOn();
}

bool PhotonCannonCommand::IsFinished()
{
	return false;
}

void PhotonCannonCommand::End()
{
	myPhotonCannonSubsystem->LightOff();
}
