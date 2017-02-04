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

void ShooterAndLoader::ReverseLoaderConveyor()
{
	LoaderConveyor.Set(-1);
}

void ShooterAndLoader::LoaderConveyorForward()
{
	LoaderConveyor.Set(1);
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

void ShooterAndLoader::ReverseShooterConveyors()
{
	SetShooterConveyorSpeed(-1);
}

void ShooterAndLoader::ShooterConveyorsOff()
{
	SetShooterConveyorSpeed(0);
}

void ShooterAndLoader::StartShooterConveyors()
{
	// Need to add the shooting feeder sequencing!!!
}
