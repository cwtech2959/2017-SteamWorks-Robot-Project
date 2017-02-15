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
	Requires(LoaderSubsystem.get());
}

ReverseLoaderCommand::~ReverseLoaderCommand()
{
}

void ReverseLoaderCommand::Initialize()
{
	LoaderSubsystem->ReverseLoaderConveyor();
}

bool ReverseLoaderCommand::IsFinished()
{
	return false;
}

void ReverseLoaderCommand::End()
{
	LoaderSubsystem->LoaderConveyorForward();
}

void ReverseLoaderCommand::Interrupted()
{
	End();
}
