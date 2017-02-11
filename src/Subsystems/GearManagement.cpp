/*
 * GearManagment.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#include <Subsystems/GearManagement.h>

GearManagement::GearManagement() :
		frc::Subsystem("GearManagement")
{
	GearGateTime = DefaultGearGateTime;
}

GearManagement::~GearManagement()
{
	// TODO Auto-generated destructor stub
}

// Public Methods Here

void GearManagement::StartGearDropOffMotors(bool open)
{
	if (open == true)
	{
		GearDropOffMotors.Set(1);
	}
	else
	{
		GearDropOffMotors.Set(-1);
	}
}

void GearManagement::StopGearDropOffMotors()
{
	GearDropOffMotors.Set(0);
}

void GearManagement::SetGearGateTime(int time)
{
	GearGateTime = time;
}

int GearManagement::GetGearGateTime()
{
	return GearGateTime;
}
