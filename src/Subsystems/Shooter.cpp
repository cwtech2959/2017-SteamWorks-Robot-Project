/*
 * ShooterAndLoader.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#include <Subsystems/Shooter.h>
#include "RobotMap.h"
#include "WPILib.h"
#include <Commands/MaintainBallFeedersSpeed.h>

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

void Shooter::InitDefaultCommand()
{
	SetDefaultCommand(new MaintainBallFeedersSpeed());
}

// Shooter feeder manipulation
void Shooter::StopBallFeeders()
{
	SetBallFeedersSpeed(0);
}

void Shooter::ReverseBallFeeders()
{
	SetBallFeedersSpeed(-1);
}

void Shooter::BallFeederOff(ShooterSide side)
{
	SetBallFeederSpeed(side, 0);
}

void Shooter::BallFeederOn(ShooterSide side)
{
	SetBallFeederSpeed(side, 1);
}

void Shooter::MaintainBallFeeders()
{
	SetBallFeederSpeed(leftShooter, rampLeft.CurrentSpeed());
	SetBallFeederSpeed(rightShooter, rampRight.CurrentSpeed());
}

// Member Access

void Shooter::SetOffsetRight(double offsetTime)
{
	StartOffsetRight = LimitOffsetTime(offsetTime);
}

void Shooter::SetOffsetLeft(double offsetTime)
{
	StartOffsetLeft = LimitOffsetTime(offsetTime);
}

void Shooter::SetOnTime(double time)
{
	OnTime = LimitOffsetTime(time);
}

void Shooter::SetOffTime(double time)
{
	OffTime = LimitOffsetTime(time);
}

double Shooter::GetOnTime()
{
	return OnTime;
}

double Shooter::GetOffTime()
{
	return OffTime;
}

double Shooter::GetOffsetTime(ShooterSide side)
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

double Shooter::LimitOffsetTime(double time)
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
	SetBallFeederSpeed(leftShooter, speed);
	SetBallFeederSpeed(rightShooter, speed);
}

void Shooter::SetBallFeederSpeed(ShooterSide side, double speed)
{
	if (side == leftShooter)
	{
		speed = rampLeft.NextSpeed(speed);
		BallFeederLeft->Set(speed);
	}
	else
	{
		speed = rampRight.NextSpeed(speed);
		BallFeederRight->Set(speed);
	}
}
