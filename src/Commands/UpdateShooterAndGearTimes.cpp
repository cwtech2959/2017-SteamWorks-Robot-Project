/*
 * UpdateShooterAndGearTimes.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#include <Commands/UpdateShooterAndGearTimes.h>
#include <Robot.h>

UpdateShooterAndGearTimes::UpdateShooterAndGearTimes() :
	Command("UpdateShooterAndGearTimes")
{
	Requires(Robot::ShooterSubsystem.get());
	Requires(Robot::GearManagementSubsystem.get());
}

UpdateShooterAndGearTimes::~UpdateShooterAndGearTimes()
{
}

void UpdateShooterAndGearTimes::Initialize()
{
	double gearGateTime = SmartDashboard::GetNumber("Gear Gate Time", DefaultGearGateTime);
	Robot::GearManagementSubsystem->SetGearGateTime(gearGateTime);
	double startOffSetRightTime = SmartDashboard::GetNumber("Start OffSet Right", StartOffSetRightTime);
	Robot::ShooterSubsystem->SetOffSetRight(startOffSetRightTime);
	double startOffSetLeft = SmartDashboard::GetNumber("Start OffSet Left", StartOffSetLeftTime);
	Robot::ShooterSubsystem->SetOffSetLeft(startOffSetLeft);
	double onTime = SmartDashboard::GetNumber("On Time", DefaultOnTime);
	Robot::ShooterSubsystem->SetOnTime(onTime);
	double offTime = SmartDashboard::GetNumber("Off Time", DefaultOffTime);
	Robot::ShooterSubsystem->SetOffTime(offTime);
}

bool UpdateShooterAndGearTimes::IsFinished()
{
	return true;
}
