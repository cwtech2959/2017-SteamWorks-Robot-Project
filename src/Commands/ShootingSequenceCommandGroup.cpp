/*
 * ShootingSequenceCommandGroup.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#include <Commands/ShootingSequenceCommandGroup.h>
#include <Commands/WaitCommand.h>
#include <Commands/StartShooterConveyorCommand.h>
#include <Robot.h>

ShootingSequenceCommandGroup::ShootingSequenceCommandGroup(Shooter::ShooterSide side)
{
	AddSequential(new WaitCommand(Robot::ShooterSubsystem->GetOffsetTime(side) * 0.001));
	for (int i = 0; i < 30; i++)
	{
		AddSequential(new StartShooterConveyorCommand(side));
		AddSequential(new WaitCommand(Robot::ShooterSubsystem->GetOffTime() * 0.001));
	}
}

ShootingSequenceCommandGroup::~ShootingSequenceCommandGroup()
{
}
