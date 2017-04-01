/*
 * Climb.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#include <Subsystems/RopeClimb.h>
#include "RobotMap.h"
#include <Commands/ClimbWithJoystick.h>

RopeClimb::RopeClimb() : Subsystem("Climb")
{
	ClimbRightMotor.reset(new CANTalon(CLIMB_RIGHT_CAN));
	ClimbLeftMotor.reset(new CANTalon(CLIMB_LEFT_CAN));

	LiveWindow::GetInstance()->AddActuator("Climb", "Climb Right Motor", ClimbRightMotor.get());
	LiveWindow::GetInstance()->AddActuator("Climb", "Climb Left Motor", ClimbLeftMotor.get());
}

RopeClimb::~RopeClimb()
{
}

void RopeClimb::InitDefaultCommand()
{
	SetDefaultCommand(new ClimbWithJoystick());
}

void RopeClimb::Climb(std::shared_ptr<Joystick> JoyStick)
{
	double input = JoyStick->GetRawAxis(3);

	ClimbRightMotor->Set(input);
	ClimbLeftMotor->Set(input);
}
