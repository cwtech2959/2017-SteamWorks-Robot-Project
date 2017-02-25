/*
 * GearManagment.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#include <Subsystems/GearManagement.h>
#include "RobotMap.h"
#include "WPILib.h"

GearManagement::GearManagement() : Subsystem("GearManagement")
{
	GearGateTime = DefaultGearGateTime;
	FryingPanUpDelay = DefaultFryingPanUpDelayTime;
	FryingPanDriveSpeed = DefaultFryingPanDriveSpeed;
	GearReleaseDriveSpeed = DefaultGearReleaseDriveSpeed;


	FryingPanDownSwitch.reset(new DigitalInput(FRYING_PAN_DOWN_DIO));
	FryingPanUpSwitch.reset(new DigitalInput(FRYING_PAN_UP_DIO));
	GearOnFryingPan.reset(new DigitalInput(GEAR_ON_FRYING_PAN_DIO));

	FryingPanMotor.reset(new Spark(FRYING_PAN_MOTOR_PWM));
	GearDropOffMotors.reset(new Spark(GEAR_DROP_OFF_MOTORS_PWM));

	FryingPanState = Unknown;

	LiveWindow * lw = LiveWindow::GetInstance();
    lw->AddActuator("GearManagement", "Frying Pan Motor", FryingPanMotor.get());
    lw->AddActuator("GearManagement", "Gear Drop Off Motors", GearDropOffMotors.get());
}

GearManagement::~GearManagement()
{
}

// Public Methods Here

void GearManagement::StartGearDropOffMotors(bool open)
{
	if (open == true)
	{
		GearDropOffMotors->Set(GearReleaseDriveSpeed);
	}
	else
	{
		GearDropOffMotors->Set(-GearReleaseDriveSpeed);
	}
}

void GearManagement::StopGearDropOffMotors()
{
	GearDropOffMotors->Set(0);
}

void GearManagement::StartFryingPanMotor(bool up)
{
	if (up == true)
	{
		FryingPanMotor->Set(-FryingPanDriveSpeed);
	}
	else
	{
		FryingPanMotor->Set(FryingPanDriveSpeed);
	}
}

void GearManagement::StopFryingPanMotor()
{
	FryingPanMotor->Set(0);
}

int GearManagement::GetGearGateTime()
{
	return GearGateTime;
}

void GearManagement::SetGearGateTime(int time)
{
	GearGateTime = time;
}

void GearManagement::SetFryingPanUpDelayTime(int time)
{
	FryingPanUpDelay = time;
}

int GearManagement::GetFryingPanUpDelayTime()
{
	return FryingPanUpDelay;
}

bool GearManagement::GetFryingPanUpSwitch()
{
	return FryingPanUpSwitch->Get();
}

bool GearManagement::GetFryingPanDownSwitch()
{
	return FryingPanDownSwitch->Get();
}

bool GearManagement::GetGearOnFryingPan()
{
	return !GearOnFryingPan->Get();
}

void GearManagement::SetDrivingFryingPan(DrivingFryingPan state)
{
	FryingPanState = state;
}

GearManagement::DrivingFryingPan GearManagement::GetDrvingFryingPan()
{
	return FryingPanState;
}

double GearManagement::GetFryingPanDriveSpeed()
{
	return FryingPanDriveSpeed;
}

void GearManagement::SetFryingPanDriveSpeed(double speed)
{
	FryingPanDriveSpeed = speed;
}

double GearManagement::GetGearReleaseDriveSpeed()
{
	return GearReleaseDriveSpeed;
}

void GearManagement::SetGearReleaseDriveSpeed(double speed)
{
	GearReleaseDriveSpeed = speed;
}
