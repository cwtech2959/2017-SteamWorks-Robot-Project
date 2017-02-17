/*
 * ClearGearTrigger.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Triggers/ClearGearTrigger.h>
#include <Subsystems/GearManagement.h>
#include <CommandBase.h>

ClearGearTrigger::ClearGearTrigger()
{
}

ClearGearTrigger::~ClearGearTrigger()
{
}

bool ClearGearTrigger::Get()
{
	return (CommandBase::GearManagementSubsystem->GearLoadReady.Get() == true
			&& (CommandBase::GearManagementSubsystem->GearOnFryingPan.Get() == true
					|| CommandBase::GearManagementSubsystem->FryingPanUpSwitch.Get() == true));

}
