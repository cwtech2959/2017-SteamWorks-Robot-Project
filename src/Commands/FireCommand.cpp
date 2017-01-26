/*
 * FireCommand.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: CW
 */

#include <Commands/FireCommand.h>

FireCommand::FireCommand() :
		CommandBase("FireCommand")
{
	// TODO Auto-generated constructor stub
	Requires(ShooterAndLoaderSubsystem.get());
}

FireCommand::~FireCommand()
{
	// TODO Auto-generated destructor stub
}

void FireCommand::Execute()
{
	ShooterAndLoaderSubsystem->StartShooterConveyors();
}

bool FireCommand::IsFinished()
{
	return false;
}
