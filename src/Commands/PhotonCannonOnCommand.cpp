/*
 * TogglePhotonCannonCommand.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#include <Commands/PhotonCannonOnCommand.h>

PhotonCannonOnCommand::PhotonCannonOnCommand() :
	CommandBase("PhotonCannonCommand")
{
	// TODO Auto-generated constructor stub
	Requires(myPhotonCannonSubsystem.get());
}

PhotonCannonOnCommand::~PhotonCannonOnCommand() {
	// TODO Auto-generated destructor stub
}

void PhotonCannonOnCommand::Execute()
{
	myPhotonCannonSubsystem->LightOn();
}

bool PhotonCannonOnCommand::IsFinished()
{
	return true;
}
