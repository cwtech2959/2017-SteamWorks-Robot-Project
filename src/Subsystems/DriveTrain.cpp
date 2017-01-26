/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: Kevin
 */

#include <Subsystems/DriveTrain.h>
#include "Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() :
		frc::Subsystem("DriveTrain")
{
	// TODO Auto-generated constructor stub

}

DriveTrain::~DriveTrain()
{
	// TODO Auto-generated destructor stub
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::TankDrive(double leftSide, double rightSide)
{
	m_TankDrive.TankDrive(leftSide, rightSide, false);
}

void DriveTrain::TankDrive(frc::Joystick * pJoystick)
{
	TankDrive(pJoystick->GetRawAxis(1), pJoystick->GetRawAxis(3));
}

void DriveTrain::Stop()
{
	TankDrive(0.0, 0.0);
	//m_TankDrive.TankDrive(0.0, 0.0, false);
}

