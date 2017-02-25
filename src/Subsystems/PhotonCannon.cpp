/*
 * PhotonCannonSubsystem.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#include <Subsystems/PhotonCannon.h>
#include "RobotMap.h"

PhotonCannon::PhotonCannon() : Subsystem("PhotonCannon")
{
	LightController.reset(new Spark(AIM_LIGHT_PWM));

	LiveWindow::GetInstance()->AddActuator("PhotonCannon", "Aim Light", LightController.get());
}

PhotonCannon::~PhotonCannon()
{
}

void PhotonCannon::LightOff()
{
	LightController->Set(0.0);
}

void PhotonCannon::LightOn()
{
	LightController->Set(0.1);
}
