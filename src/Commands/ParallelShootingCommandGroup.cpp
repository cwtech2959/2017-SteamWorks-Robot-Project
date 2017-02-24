/*
 * ParallelShootingCommandGroup.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/ParallelShootingCommandGroup.h>
#include <Commands/ShootingSequenceCommandGroup.h>
#include <Subsystems/Shooter.h>
#include <Robot.h>

ParallelShootingCommandGroup::ParallelShootingCommandGroup()
{
	AddParallel(new ShootingSequenceCommandGroup(Shooter::leftShooter));
	AddParallel(new ShootingSequenceCommandGroup(Shooter::rightShooter));
}

ParallelShootingCommandGroup::~ParallelShootingCommandGroup()
{
}

void ParallelShootingCommandGroup::Initialize()
{
	Robot::ShooterSubsystem->SetShooting(true);
}

void ParallelShootingCommandGroup::End()
{
	Robot::ShooterSubsystem->SetShooting(false);
}

void ParallelShootingCommandGroup::Interrupted()
{
	End();
}
