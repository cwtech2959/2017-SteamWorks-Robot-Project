/*
 * Loader.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#include <Subsystems/Loader.h>

Loader::Loader() :
	frc::Subsystem("Loader")
{
}

Loader::~Loader()
{
}

void Loader::StopLoaderConveyor()
{
	LoaderConveyor.Set(0);
}

void Loader::ReverseLoaderConveyor()
{
	StopLoaderConveyor();
	LoaderConveyor.Set(-1);
}

void Loader::LoaderConveyorForward()
{
	StopLoaderConveyor();
	LoaderConveyor.Set(1);
}
