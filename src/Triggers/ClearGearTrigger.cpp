/*
 * ClearGearTrigger.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Triggers/ClearGearTrigger.h>
#include <Subsystems/GearLoad.h>
#include <Robot.h>
#include <Subsystems/GearManagement.h>

ClearGearTrigger::ClearGearTrigger()
{
}

ClearGearTrigger::~ClearGearTrigger()
{
}

bool ClearGearTrigger::Get()
{
	return (Robot::GearLoadSubsystem->GetGearLoadReady() == true
			&& (Robot::GearManagementSubsystem->GetGearOnFryingPan() == true
					|| Robot::GearManagementSubsystem->GetFryingPanUpSwitch() == true));
}
