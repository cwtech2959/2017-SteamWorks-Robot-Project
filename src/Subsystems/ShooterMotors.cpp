/*
 * ShooterMotors.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: CW
 */

#include <Subsystems/ShooterMotors.h>
#include <RobotMap.h>

ShooterMotors::ShooterMotors() : Subsystem("ShooterMotors")
{
	BallShooterLeft.reset(new CANTalon(BALL_SHOOTER_LEFT_CAN));
	BallShooterRight.reset(new CANTalon(BALL_SHOOTER_RIGHT_CAN));
}

ShooterMotors::~ShooterMotors()
{
}

void ShooterMotors::SetBallShootersSpeed(double speed)
{
	BallShooterLeft->Set(speed);
	BallShooterRight->Set(speed);
}
