/*
 * Loader.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#include <Subsystems/Loader.h>
#include "RobotMap.h"

Loader::Loader() : Subsystem("Loader")
{
	BallPickupAndAgitator.reset(new Spark(BALL_PICKUP_PWM));

	LiveWindow::GetInstance()->AddActuator("Loader", "Ball Pickup and Agitation", BallPickupAndAgitator.get());
}

Loader::~Loader()
{
}

void Loader::StopBallLoader()
{
	BallPickupAndAgitator->Set(0);
}

void Loader::ReverseBallLoader()
{
	StopBallLoader();
	BallPickupAndAgitator->Set(-1);
}

void Loader::BallLoaderForward()
{
	StopBallLoader();
	BallPickupAndAgitator->Set(1);
}
