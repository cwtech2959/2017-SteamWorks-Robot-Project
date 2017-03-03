/*
 * MaintainShooterSpeed.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: mriri
 */

#include <Commands/MaintainBallFeedersSpeed.h>
#include <Robot.h>

MaintainBallFeedersSpeed::MaintainBallFeedersSpeed():
	Command("MaintainBallFeedersSpeed")
{
	Requires(Robot::ShooterSubsystem.get());
}

MaintainBallFeedersSpeed::~MaintainBallFeedersSpeed()
{
}

void MaintainBallFeedersSpeed::Execute()
{
	Robot::ShooterSubsystem->MaintainBallFeeders();
}

bool MaintainBallFeedersSpeed::IsFinished()
{
	return false;
}
