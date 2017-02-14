/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#include <Subsystems/DriveTrain.h>
#include "Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() :
		frc::Subsystem("DriveTrain")
{
	DriveTank.SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, false);
	DriveTank.SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, false);
	DriveTank.SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
	DriveTank.SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);
}

DriveTrain::~DriveTrain()
{
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::TankDrive(frc::Joystick*pJoystick)
{
	TankDrive(pJoystick->GetRawAxis(1), pJoystick->GetRawAxis(3));
}

void DriveTrain::Stop()
{
	TankDrive(0.0, 0.0);
}

void DriveTrain::TankDrive(double leftSide, double rightSide)
{
	DriveTank.TankDrive(leftSide, rightSide, false);
}
