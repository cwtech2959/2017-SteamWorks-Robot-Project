/*
 * LoadCommand.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#include <Commands/LoadCommand.h>

LoadCommand::LoadCommand() :
		CommandBase("LoadCommand")
{
	// TODO Auto-generated constructor stub
	Requires(ShooterAndLoaderSubsystem.get());
}

LoadCommand::~LoadCommand()
{
	// TODO Auto-generated destructor stub
}

void LoadCommand::Execute()
{
	ShooterAndLoaderSubsystem->StartLoaderConveyor();
}

bool LoadCommand::IsFinished()
{
	return false;
}
