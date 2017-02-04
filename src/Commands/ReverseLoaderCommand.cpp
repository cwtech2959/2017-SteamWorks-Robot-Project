/*
 * LoadCommand.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#include <Commands/ReverseLoaderCommand.h>

ReverseLoaderCommand::ReverseLoaderCommand() :
		CommandBase("ReverseLoaderCommand")
{
	Requires(ShooterAndLoaderSubsystem.get());
}

ReverseLoaderCommand::~ReverseLoaderCommand()
{
}

void ReverseLoaderCommand::Execute()
{
	ShooterAndLoaderSubsystem->ReverseLoaderConveyor();
}

bool ReverseLoaderCommand::IsFinished()
{
	return false;
}

void ReverseLoaderCommand::End()
{
	ShooterAndLoaderSubsystem->LoaderConveyorForward();
}

void ReverseLoaderCommand::Interrupted()
{
	End();
}
