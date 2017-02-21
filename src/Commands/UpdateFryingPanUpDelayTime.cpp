/*
 * UpdateFryingPanUpDelayTime.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: mriri
 */

#include <Commands/UpdateFryingPanUpDelayTime.h>
#include <SmartDashboard/SmartDashboard.h>

UpdateFryingPanUpDelayTime::UpdateFryingPanUpDelayTime() :CommandBase("UpdateFryingPanUpDelayTime")
{
	Requires(GearManagementSubsystem.get());

}

UpdateFryingPanUpDelayTime::~UpdateFryingPanUpDelayTime()
{

}

void UpdateFryingPanUpDelayTime::Initialize()
{
	double fryingPanUpDelayTime = frc::SmartDashboard::GetNumber("Frying Pan Up Delay Time", DefaultClearTime);
			GearManagementSubsystem->SetGearGateTime(fryingPanUpDelayTime);
}

bool UpdateFryingPanUpDelayTime::IsFinished()
{
	return true;
}
