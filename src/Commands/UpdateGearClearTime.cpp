/*
 * UpdateGearClearTime.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Commands/UpdateGearClearTime.h>
#include <SmartDashboard/SmartDashboard.h>

UpdateGearClearTime::UpdateGearClearTime() : CommandBase("UpdateGearClearTime")
{
	Requires(GearManagementSubsystem.get());

}

UpdateGearClearTime::~UpdateGearClearTime()
{

}

void UpdateGearClearTime::Initialize()
{
	double gearClearTime = frc::SmartDashboard::GetNumber("Gear Clear Time", DefaultClearTime);
		GearManagementSubsystem->SetGearGateTime(gearClearTime);
}

bool UpdateGearClearTime::IsFinished()
{
	return true;
}
