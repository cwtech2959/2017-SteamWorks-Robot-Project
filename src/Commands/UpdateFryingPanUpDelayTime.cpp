/*
 * UpdateFryingPanUpDelayTime.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: mriri
 */

#include <Commands/UpdateFryingPanUpDelayTime.h>
#include <Robot.h>

UpdateFryingPanUpDelayTime::UpdateFryingPanUpDelayTime() : Command("UpdateFryingPanUpDelayTime")
{
	Requires(Robot::GearManagementSubsystem.get());
}

UpdateFryingPanUpDelayTime::~UpdateFryingPanUpDelayTime()
{
}

void UpdateFryingPanUpDelayTime::Initialize()
{
	double fryingPanUpDelayTime = SmartDashboard::GetNumber("Frying Pan Up Delay Time", DefaultClearTime);
	Robot::GearManagementSubsystem->SetGearGateTime(fryingPanUpDelayTime);
}

bool UpdateFryingPanUpDelayTime::IsFinished()
{
	return true;
}
