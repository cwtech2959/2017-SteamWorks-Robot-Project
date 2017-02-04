/*
 * ShootingSequenceCommandGroup.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/ShootingSequenceCommandGroup.h>
#include <Commands/WaitCommand.h>
#include <CommandBase.h>
#include <Commands/StartShooterConveyorCommand.h>

ShootingSequenceCommandGroup::ShootingSequenceCommandGroup(ShooterAndLoader::ShooterSide side)
{
	AddSequential(new WaitCommand(CommandBase::ShooterAndLoaderSubsystem->GetOffsetTime(side) * 0.001));
	for (int i = 0; i < 30; i++)
	{
		AddSequential(new StartShooterConveyorCommand(side));
		AddSequential(new WaitCommand(CommandBase::ShooterAndLoaderSubsystem->GetOffTime() * 0.001));
	}
}

ShootingSequenceCommandGroup::~ShootingSequenceCommandGroup()
{
}

