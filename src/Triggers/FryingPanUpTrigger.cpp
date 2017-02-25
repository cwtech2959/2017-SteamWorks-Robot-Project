/*
 * FryingPanUpTrigger.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: mriri
 */

#include <Triggers/FryingPanUpTrigger.h>
#include <Subsystems/GearManagement.h>
#include <Robot.h>

FryingPanUpTrigger::FryingPanUpTrigger()
{
}

FryingPanUpTrigger::~FryingPanUpTrigger()
{
}

bool FryingPanUpTrigger::Get()
{
	return (Robot::GearManagementSubsystem->GetGearOnFryingPan() == true &&
			Robot::GearManagementSubsystem->GetDrvingFryingPan() == GearManagement::Down);
}
