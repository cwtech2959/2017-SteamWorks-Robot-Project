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

Shooter::Shooter() : Subsystem("ShooterAndLoader")
{
	StartOffSetRight = StartOffSetRightTime;
	StartOffSetLeft = StartOffSetLeftTime;

	OnTime = DefaultOnTime;
	OffTime = DefaultOffTime;

	Shooting = false;

	ShooterConveyorRight.reset(new Spark(BALL_FEEDER_RIGHT_PWM));
	ShooterConveyorLeft.reset(new Spark(BALL_FEEDER_LEFT_PWM));
	BallShooterLeft.reset(new CANTalon(BALL_SHOOTER_LEFT_CAN));
	BallShooterRight.reset(new CANTalon(BALL_SHOOTER_RIGHT_CAN));
}

Shooter::~Shooter()
{
}

void Shooter::StopAllConveyors()
{
	SetShooterConveyorsSpeed(0);
}

// Loader Conveyor manipulation


// Shooter feeder manipulation
void Shooter::StartShooterConveyors()
{
	// Need to add the shooting feeder sequencing!!!
}

void Shooter::ShooterConveyorsOff()
{
	SetShooterConveyorsSpeed(0);
}

void Shooter::ReverseShooterConveyors()
{
	SetShooterConveyorsSpeed(-1);
}

void Shooter::ShooterConveyorOff(ShooterSide side)
{
	SetShooterConveyorSpeed(side, 0);
}

void Shooter::ShooterConveyorOn(ShooterSide side)
{
	SetShooterConveyorSpeed(side, 1);
}

// Member Access

void Shooter::SetOffSetRight(int offsetTime)
{
	StartOffSetRight = LimitOffsetTime(offsetTime);
}

void Shooter::SetOffSetLeft(int offsetTime)
{
	StartOffSetLeft = LimitOffsetTime(offsetTime);
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
		return StartOffSetLeft;
	}
	else
	{
		return StartOffSetRight;
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

void Shooter::SetShooterConveyorsSpeed(double speed)
{
	SetShooterConveyorSpeed(leftShooter, speed);
	SetShooterConveyorSpeed(rightShooter, speed);
}

void Shooter::SetShooterConveyorSpeed(ShooterSide side, double speed)
{
	if (side == leftShooter)
	{
		ShooterConveyorLeft->Set(speed);
	}
	else
	{
		ShooterConveyorRight->Set(speed);
	}
}

void Shooter::SetBallShootersSpeed(double speed)
{
	BallShooterLeft->Set(speed);
	BallShooterRight->Set(speed);
}
