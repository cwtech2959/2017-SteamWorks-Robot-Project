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

}

ShooterAndLoader::~ShooterAndLoader()
{
	// TODO Auto-generated destructor stub
}

void ShooterAndLoader::StopAllConveyors()
{
	ShooterConveyorRight.Set(0);
	ShooterConveyorLeft.Set(0);
	LoaderConveyor.Set(0);
}

void ShooterAndLoader::StartLoaderConveyor()
{
	LoaderConveyor.Set(1);
}

void ShooterAndLoader::StartShooterConveyors()
{
	ShooterConveyorRight.Set(1);
	ShooterConveyorLeft.Set(1);
}
