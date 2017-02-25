/*
 * GearLoad.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: mriri
 */

#include <Subsystems/GearLoad.h>
#include <RobotMap.h>
#include "WPILib.h"

GearLoad::GearLoad() : Subsystem("GearLoad")
{
	GearClearTime = DefaultClearTime;

	GearLoadReady.reset(new DigitalInput(GEAR_LOAD_READY_DIO));
	GearPickup.reset(new CANTalon(3));
}

GearLoad::~GearLoad()
{
}

bool GearLoad::GetGearLoadReady()
{
	return GearLoadReady->Get();
}

void GearLoad::SetGearClearTime(int time)
{
	GearClearTime = time;
}
