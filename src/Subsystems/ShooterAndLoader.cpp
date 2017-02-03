/*
 * ShooterAndLoader.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#include <Subsystems/ShooterAndLoader.h>

const int MinTimeLimit = 0;
const int MaxTimeLimit = 5000;

ShooterAndLoader::ShooterAndLoader() :
		frc::Subsystem("ShooterAndLoader")
{
	ShooterConveyorState = false;
	LoaderConveyorState = false;

	StartOffSetRight = 0;
	StartOffSetLeft = 0;

	OnTime = 0;
	OffTime = 0;
}

ShooterAndLoader::~ShooterAndLoader()
{
}

void ShooterAndLoader::StopAllConveyors()
{
	SetShooterConveyorSpeed(0);
	LoaderConveyor.Set(0);
}

void ShooterAndLoader::ToggleLoaderConveyor()
{
	if (LoaderConveyorState == true)
	{
		LoaderConveyorState = false;
		LoaderConveyor.Set(0);
	}
	else
	{
		LoaderConveyorState = true;
		LoaderConveyor.Set(1);
	}
}

void ShooterAndLoader::ToggleShooterConveyors()
{
	if (ShooterConveyorState == true)
	{
		ShooterConveyorState = false;
		SetShooterConveyorSpeed(0);
	}
	else
	{
		ShooterConveyorState = true;
		SetShooterConveyorSpeed(1);
	}
}

void ShooterAndLoader::SetShooterConveyorSpeed(double speed)
{
	ShooterConveyorRight.Set(speed);
	ShooterConveyorLeft.Set(speed);
}

void ShooterAndLoader::SetOffSetRight(int offsetTime)
{
	StartOffSetRight = LimitOffsetTime(offsetTime);
}

void ShooterAndLoader::SetOffSetLeft(int offsetTime)
{
	StartOffSetLeft = LimitOffsetTime(offsetTime);
}

void ShooterAndLoader::SetOnTime(int time)
{
	OnTime = LimitOffsetTime(time);
}

void ShooterAndLoader::SetOffTime(int time)
{
	OffTime = LimitOffsetTime(time);
}

int ShooterAndLoader::LimitOffsetTime(int time)
{
	if (time < MinTimeLimit)
	{
		time = MinTimeLimit;
	}
	else if (time > MaxTimeLimit)
	{
		time = MaxTimeLimit;
	}

	return time;
}
