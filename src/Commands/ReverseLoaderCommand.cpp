/*
 * LoadCommand.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#include <Commands/ReverseLoaderCommand.h>
#include <Robot.h>

ReverseLoaderCommand::ReverseLoaderCommand() :
		Command("ReverseLoaderCommand")
{
	Requires(Robot::LoaderSubsystem.get());
}

ReverseLoaderCommand::~ReverseLoaderCommand()
{
}

void ReverseLoaderCommand::Initialize()
{
	Robot::LoaderSubsystem->ReverseLoaderConveyor();
}

bool ReverseLoaderCommand::IsFinished()
{
	return false;
}

void ReverseLoaderCommand::End()
{
	Robot::LoaderSubsystem->LoaderConveyorForward();
}

void ReverseLoaderCommand::Interrupted()
{
	End();
}
