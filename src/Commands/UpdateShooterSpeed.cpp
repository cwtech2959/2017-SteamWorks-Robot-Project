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
	Requires(ShooterAndLoaderSubsystem.get());
}

UpdateShooterSpeed::~UpdateShooterSpeed()
{
}

void UpdateShooterSpeed::Initialize()
{
	double speed = frc::SmartDashboard::GetNumber("Shooter Speed", DefaultShooterSpeed);
	ShooterAndLoaderSubsystem->SetBallShootersSpeed(speed);
}

bool UpdateShooterSpeed::IsFinished()
{
	return true;
}
