/*
 * MaintainLoaderSpeed.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: mriri
 */

#include <Commands/MaintainLoaderSpeed.h>
#include <Robot.h>

MaintainLoaderSpeed::MaintainLoaderSpeed() :
	Command("MaintainLoaderSpeed")
{
	Requires(Robot::LoaderSubsystem.get());
}

MaintainLoaderSpeed::~MaintainLoaderSpeed()
{
}

void MaintainLoaderSpeed::Execute()
{
	Robot::LoaderSubsystem->MaintainLoader();
}

bool MaintainLoaderSpeed::IsFinished()
{
	return false;
}
