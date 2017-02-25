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
	GearPickup.reset(new CANTalon(GEAR_PICK_UP_ROLLER_CAN));

	LiveWindow::GetInstance()->AddActuator("GearLoad", "Gear Pickup Roller CIM", GearPickup.get());
}

GearLoad::~GearLoad()
{
}

void GearLoad::Stop()
{
	GearPickup->Set(0.0);
}

void GearLoad::LoadGear()
{
	GearPickup->Set(-1.0);
}

void GearLoad::ClearGear()
{
	GearPickup->Set(1.0);
}

bool GearLoad::GetGearLoadReady()
{
	return GearLoadReady->Get();
}

int GearLoad::GetGearClearTime()
{
	return GearClearTime;
}

void GearLoad::SetGearClearTime(int time)
{
	GearClearTime = time;
}
