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
	FryingPanStallTime = DefaultFryingPanStallTime;
	GearClearTime = DefaultClearTime;
	FryingPanUpDelay = DefaultFryingPanUpDelayTime;
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

void GearManagement::StartFryingPanMotor(bool up)
{
	if (up == true)
		{
			FryingPanMotor.Set(1);
		}
		else
		{
			FryingPanMotor.Set(-1);
		}
}

void GearManagement::StopFryingPanMotor()
{
	FryingPanMotor.Set(0);
}

void GearManagement::SetGearGateTime(int time)
{
	GearGateTime = time;
}

int GearManagement::GetGearGateTime()
{
	return GearGateTime;
}

void GearManagement::SetFryingPanStallTime(int time)
{
	FryingPanStallTime = time;
}
int GearManagement::GetFryingPanStallTime()
{
	return FryingPanStallTime;
}

bool GearManagement::GetFryingPanUpSwitch()
{
	return FryingPanUpSwitch.Get();
}

bool GearManagement::GetFryingPanDownSwitch()
{
	return FryingPanDownSwitch.Get();

}

void GearManagement::SetGearClearTime(int time)
{
	GearClearTime = time;
}
