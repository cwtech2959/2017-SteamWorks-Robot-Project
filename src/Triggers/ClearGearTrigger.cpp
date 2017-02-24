/*
 * ClearGearTrigger.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Triggers/ClearGearTrigger.h>
#include <Subsystems/GearManagement.h>
#include <Robot.h>

ClearGearTrigger::ClearGearTrigger()
{
}

ClearGearTrigger::~ClearGearTrigger()
{
}

bool ClearGearTrigger::Get()
{
	return (Robot::GearManagementSubsystem->GetGearLoadReady() == true
			&& (Robot::GearManagementSubsystem->GetGearOnFryingPan() == true
					|| Robot::GearManagementSubsystem->GetFryingPanUpSwitch() == true));
}
