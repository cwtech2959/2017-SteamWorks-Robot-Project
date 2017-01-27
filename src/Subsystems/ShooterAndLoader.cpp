/*
 * ShooterAndLoader.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#include <Subsystems/ShooterAndLoader.h>

ShooterAndLoader::ShooterAndLoader() :
		frc::Subsystem("ShooterAndLoader")
{
	// TODO Auto-generated constructor stub
	ShooterConveyorState = false;
	LoaderConveyorState = false;
}

ShooterAndLoader::~ShooterAndLoader()
{
	// TODO Auto-generated destructor stub
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
