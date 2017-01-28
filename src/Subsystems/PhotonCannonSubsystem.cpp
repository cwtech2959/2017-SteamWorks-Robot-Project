/*
 * PhotonCannonSubsystem.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#include <Subsystems/PhotonCannonSubsystem.h>

PhotonCannonSubsystem::PhotonCannonSubsystem() : frc::Subsystem("PhotonCannon")
{
	// TODO Auto-generated constructor stub
}

PhotonCannonSubsystem::~PhotonCannonSubsystem()
{
	// TODO Auto-generated destructor stub
}

void PhotonCannonSubsystem::LightOff()
{
	LightController.Set(0.0);
}

void PhotonCannonSubsystem::LightOn()
{
	LightController.Set(0.1);
}
