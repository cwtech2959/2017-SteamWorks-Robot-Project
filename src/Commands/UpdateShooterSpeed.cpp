/*
 * UpdateShooterSpeed.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#include <Commands/UpdateShooterSpeed.h>
#include <Robot.h>

UpdateShooterSpeed::UpdateShooterSpeed() :
	Command("UpdateShooterSpeedCommand")
{
	Requires(Robot::ShooterSubsystem.get());
}

UpdateShooterSpeed::~UpdateShooterSpeed()
{
}

void UpdateShooterSpeed::Initialize()
{
	double speed = SmartDashboard::GetNumber("Shooter Speed", DefaultShooterSpeed);
	Robot::ShooterSubsystem->SetBallShootersSpeed(speed);
}

bool UpdateShooterSpeed::IsFinished()
{
	return true;
}
