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

	Shooting = false;
}

ShooterAndLoader::~ShooterAndLoader()
{
}

void ShooterAndLoader::StopAllConveyors()
{
	SetShooterConveyorsSpeed(0);
	LoaderConveyor.Set(0);
}

// Loader Conveyor manipulation
void ShooterAndLoader::ReverseLoaderConveyor()
{
	LoaderConveyor.Set(-1);
}

void ShooterAndLoader::LoaderConveyorForward()
{
	LoaderConveyor.Set(1);
}

// Shooter feeder manipulation
void ShooterAndLoader::StartShooterConveyors()
{
	// Need to add the shooting feeder sequencing!!!
}

void ShooterAndLoader::ShooterConveyorsOff()
{
	SetShooterConveyorsSpeed(0);
}

void ShooterAndLoader::ReverseShooterConveyors()
{
	SetShooterConveyorsSpeed(-1);
}

void ShooterAndLoader::ShooterConveyorOff(ShooterSide side)
{
	SetShooterConveyorSpeed(side, 0);
}

void ShooterAndLoader::ShooterConveyorOn(ShooterSide side)
{
	SetShooterConveyorSpeed(side, 1);
}

// Member Access

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

int ShooterAndLoader::GetOnTime()
{
	return OnTime;
}

int ShooterAndLoader::GetOffTime()
{
	return OffTime;
}

int ShooterAndLoader::GetOffsetTime(ShooterSide side)
{
	if (side == leftShooter)
	{
		return StartOffSetLeft;
	}
	else
	{
		return StartOffSetRight;
	}
}

void ShooterAndLoader::SetShooting(bool state)
{
	Shooting = state;
}

bool ShooterAndLoader::GetShooting()
{
	return Shooting;
}

// Private Methods

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

void ShooterAndLoader::SetShooterConveyorsSpeed(double speed)
{
	SetShooterConveyorSpeed(leftShooter, speed);

	SetShooterConveyorSpeed(rightShooter, speed);
}

void ShooterAndLoader::SetShooterConveyorSpeed(ShooterSide side, double speed)
{
	if (side == leftShooter)
	{
		ShooterConveyorLeft.Set(speed);
	}
	else
	{
		ShooterConveyorRight.Set(speed);
	}
}
