/*
 * LoadCommand.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#include <Commands/ToggleLoadCommand.h>

ToggleLoadCommand::ToggleLoadCommand() :
		CommandBase("LoadCommand")
{
	// TODO Auto-generated constructor stub
	Requires(ShooterAndLoaderSubsystem.get());
}

ToggleLoadCommand::~ToggleLoadCommand()
{
	// TODO Auto-generated destructor stub
}

void ToggleLoadCommand::Execute()
{
	ShooterAndLoaderSubsystem->ToggleLoaderConveyor();
}

bool ToggleLoadCommand::IsFinished()
{
	return true;
}
