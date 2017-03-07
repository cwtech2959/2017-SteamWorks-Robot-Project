/*
 * Loader.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#include <Commands/MaintainLoaderSpeed.h>
#include <Subsystems/Loader.h>
#include "RobotMap.h"
#include <WPILib.h>

Loader::Loader() : Subsystem("Loader")
{
	GearClearTime = DefaultClearTime;
	m_loaderTargetSpeed = 0;

	BallPickupAndAgitator.reset(new Spark(BALL_PICKUP_PWM));

	LiveWindow::GetInstance()->AddActuator("Loader", "Ball Pickup and Agitation", BallPickupAndAgitator.get());
}

Loader::~Loader()
{
}

void Loader::InitDefaultCommand()
{
	SetDefaultCommand(new MaintainLoaderSpeed());
}

void Loader::ReverseBallLoader()
{
	SetBallLoadersSpeed(1);
}

void Loader::BallLoaderForward()
{
	SetBallLoadersSpeed(-1);
}

double Loader::GetGearClearTime()
{
	return GearClearTime;
}

void Loader::SetGearClearTime(double time)
{
	GearClearTime = time;
}

void Loader::SetBallLoadersSpeed(double speed)
{
	m_loaderTargetSpeed = speed;

	speed = rampPickup.NextSpeed(speed);
	BallPickupAndAgitator->Set(speed);
}

void Loader::MaintainLoader()
{
	SetBallLoadersSpeed(m_loaderTargetSpeed);
}
