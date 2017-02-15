/*
 * UpdateShooterSpeed.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#include <Commands/UpdateShooterSpeed.h>
#include <SmartDashboard/SmartDashboard.h>

UpdateShooterSpeed::UpdateShooterSpeed() :
	CommandBase("UpdateShooterSpeedCommand")
{
	Requires(ShooterSubsystem.get());
}

UpdateShooterSpeed::~UpdateShooterSpeed()
{
}

void UpdateShooterSpeed::Initialize()
{
	double speed = frc::SmartDashboard::GetNumber("Shooter Speed", DefaultShooterSpeed);
	ShooterSubsystem->SetBallShootersSpeed(speed);
}

bool UpdateShooterSpeed::IsFinished()
{
	return true;
}
