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
	Requires(Robot::GearLoadSubsystem.get());
}

UpdateShooterAndGearTimes::~UpdateShooterAndGearTimes()
{
}

void UpdateShooterAndGearTimes::Initialize()
{
	double gearGateTime = SmartDashboard::GetNumber("Gear Gate Time", DefaultGearGateTime);
	Robot::GearManagementSubsystem->SetGearGateTime(gearGateTime);
	double gearClearTime = SmartDashboard::GetNumber("Gear Clear Time", DefaultClearTime);
	Robot::GearLoadSubsystem->SetGearClearTime(gearClearTime);
	double startOffsetRightTime = SmartDashboard::GetNumber("Ball Feeder Right Start Offset", DefaultStartOffsetRightTime);
	Robot::ShooterSubsystem->SetOffsetRight(startOffsetRightTime);
	double startOffsetLeft = SmartDashboard::GetNumber("Ball Feeder Left Start Offset", DefaultStartOffsetLeftTime);
	Robot::ShooterSubsystem->SetOffsetLeft(startOffsetLeft);
	double onTime = SmartDashboard::GetNumber("Ball Feeder On Time", DefaultOnTime);
	Robot::ShooterSubsystem->SetOnTime(onTime);
	double offTime = SmartDashboard::GetNumber("Ball Feeder Off Time", DefaultOffTime);
	Robot::ShooterSubsystem->SetOffTime(offTime);
	double fryingPanUpDelayTime = SmartDashboard::GetNumber("Frying Pan Up Delay Time", DefaultFryingPanUpDelayTime);
	Robot::GearManagementSubsystem->SetFryingPanUpDelayTime(fryingPanUpDelayTime);
	double fryingPanStallTime = SmartDashboard::GetNumber("Frying Pan Stall Time", DefaultFryingPanStallTime);
	Robot::GearManagementSubsystem->SetFryingPanStallTime(fryingPanStallTime);
}

bool UpdateShooterAndGearTimes::IsFinished()
{
	return true;
}
