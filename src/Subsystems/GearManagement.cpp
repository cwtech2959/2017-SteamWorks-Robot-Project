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

void GearManagement::MoveGearDropOff(bool open, double speed)
{
	if (open == true)
	{
		GearDropOffMotors->Set(-speed);
	}
	else
	{
		GearDropOffMotors->Set(speed);
	}
}

void GearManagement::MoveFryingPan(bool up, double speed)
{
	if (up == true)
	{
		FryingPanMotor->Set(speed);
	}
	else
	{
		FryingPanMotor->Set(-speed);
	}
}

double GearManagement::GetGearGateTime()
{
	return GearGateTime;
}

void GearManagement::SetGearGateTime(double time)
{
	GearGateTime = time;
}

void GearManagement::SetFryingPanUpDelayTime(double time)
{
	FryingPanUpDelay = time;
}

double GearManagement::GetFryingPanUpDelayTime()
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

void GearManagement::PrepareGearInit()
{
	if (FryingPanUpSwitch->Get() == true)
	{
		SetDrivingFryingPan(Up);
	}
	else if (FryingPanDownSwitch->Get() == true)
	{
		SetDrivingFryingPan(Down);
	}
	else
	{
		// Drive frying pan up
	}
}
