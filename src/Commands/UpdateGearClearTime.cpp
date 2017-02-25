/*
 * UpdateGearClearTime.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Commands/UpdateGearClearTime.h>
#include <Robot.h>

UpdateGearClearTime::UpdateGearClearTime() : Command("UpdateGearClearTime")
{
	Requires(Robot::GearLoadSubsystem.get());
	Requires(Robot::GearManagementSubsystem.get());
}

UpdateGearClearTime::~UpdateGearClearTime()
{
}

void UpdateGearClearTime::Initialize()
{
	double gearClearTime = SmartDashboard::GetNumber("Gear Clear Time", DefaultClearTime);
	Robot::GearManagementSubsystem->SetGearGateTime(gearClearTime);
}

bool UpdateGearClearTime::IsFinished()
{
	return true;
}
