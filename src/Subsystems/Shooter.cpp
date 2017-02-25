/*
 * ShooterAndLoader.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#include <Subsystems/Shooter.h>
#include "RobotMap.h"

const int MinTimeLimit = 0;
const int MaxTimeLimit = 5000;

Shooter::Shooter() : Subsystem("Shooter")
{
	StartOffsetRight = DefaultStartOffsetRightTime;
	StartOffsetLeft = DefaultStartOffsetLeftTime;

	OnTime = DefaultOnTime;
	OffTime = DefaultOffTime;

	Shooting = false;

	BallFeederRight.reset(new Spark(BALL_FEEDER_RIGHT_PWM));
	BallFeederLeft.reset(new Spark(BALL_FEEDER_LEFT_PWM));

	LiveWindow * lw = LiveWindow::GetInstance();
    lw->AddActuator("Shooter", "Ball Feeder Right Motor", BallFeederRight.get());
    lw->AddActuator("Shooter", "Ball Feeder Left Motor", BallFeederLeft.get());
}

Shooter::~Shooter()
{
}

// Shooter feeder manipulation
void Shooter::StopBallFeeders()
{
	SetBallFeedersSpeed(0);
}

void Shooter::StartBallFeeders()
{
	// Need to add the shooting feeder sequencing!!!
}

void Shooter::ReverseBallFeeders()
{
	SetBallFeedersSpeed(-1);
}

void Shooter::BallFeederOff(ShooterSide side)
{
	SetBallFeedersSpeed(side, 0);
}

void Shooter::BallFeederOn(ShooterSide side)
{
	SetBallFeedersSpeed(side, 1);
}

// Member Access

void Shooter::SetOffsetRight(int offsetTime)
{
	StartOffsetRight = LimitOffsetTime(offsetTime);
}

void Shooter::SetOffsetLeft(int offsetTime)
{
	StartOffsetLeft = LimitOffsetTime(offsetTime);
}

void Shooter::SetOnTime(int time)
{
	OnTime = LimitOffsetTime(time);
}

void Shooter::SetOffTime(int time)
{
	OffTime = LimitOffsetTime(time);
}

int Shooter::GetOnTime()
{
	return OnTime;
}

int Shooter::GetOffTime()
{
	return OffTime;
}

int Shooter::GetOffsetTime(ShooterSide side)
{
	if (side == leftShooter)
	{
		return StartOffsetLeft;
	}
	else
	{
		return StartOffsetRight;
	}
}

void Shooter::SetShooting(bool state)
{
	Shooting = state;
}

bool Shooter::GetShooting()
{
	return Shooting;
}

// Private Methods

int Shooter::LimitOffsetTime(int time)
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

void Shooter::SetBallFeedersSpeed(double speed)
{
	SetBallFeedersSpeed(leftShooter, speed);
	SetBallFeedersSpeed(rightShooter, speed);
}

void Shooter::SetBallFeedersSpeed(ShooterSide side, double speed)
{
	if (side == leftShooter)
	{
		BallFeederLeft->Set(speed);
	}
	else
	{
		BallFeederRight->Set(speed);
	}
}
