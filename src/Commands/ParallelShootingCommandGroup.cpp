/*
 * ParallelShootingCommandGroup.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/ParallelShootingCommandGroup.h>
#include <Commands/ShootingSequenceCommandGroup.h>
#include <Subsystems/ShooterAndLoader.h>
#include <CommandBase.h>

ParallelShootingCommandGroup::ParallelShootingCommandGroup()
{
	AddParallel(new ShootingSequenceCommandGroup(ShooterAndLoader::leftShooter));
	AddParallel(new ShootingSequenceCommandGroup(ShooterAndLoader::rightShooter));
}

ParallelShootingCommandGroup::~ParallelShootingCommandGroup()
{
}

void ParallelShootingCommandGroup::Initialize()
{
	CommandBase::ShooterAndLoaderSubsystem->SetShooting(true);
}

void ParallelShootingCommandGroup::End()
{
	CommandBase::ShooterAndLoaderSubsystem->SetShooting(false);
}

void ParallelShootingCommandGroup::Interrupted()
{
	End();
}
