/*
 * FireCommand.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: CW
 */

#include <Commands/ToggleFireCommand.h>

ToggleFireCommand::ToggleFireCommand() :
		CommandBase("FireCommand")
{
	// TODO Auto-generated constructor stub
	Requires(ShooterAndLoaderSubsystem.get());
}

ToggleFireCommand::~ToggleFireCommand()
{
	// TODO Auto-generated destructor stub
}

void ToggleFireCommand::Execute()
{
	ShooterAndLoaderSubsystem->ToggleShooterConveyors();
}

bool ToggleFireCommand::IsFinished()
{
	return true;
}
