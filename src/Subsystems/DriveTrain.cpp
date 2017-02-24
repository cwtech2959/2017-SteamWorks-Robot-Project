/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#include <Subsystems/DriveTrain.h>
#include <Commands/DriveWithJoystick.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	InitHardware();
}

DriveTrain::~DriveTrain()
{
}

void DriveTrain::InitHardware()
{
	Left1MotorController.reset(new CANTalon(5));
	Left2MotorController.reset(new CANTalon(6));
	Right1MotorController.reset(new CANTalon(1));
	Right2MotorController.reset(new CANTalon(2));

	DriveTank.reset(new RobotDrive(
			Left1MotorController,
			Left2MotorController,
			Right1MotorController,
			Right2MotorController));

    LiveWindow * lw = LiveWindow::GetInstance();
    lw->AddActuator("DriveTrain", "Left 1 CIM", Left1MotorController.get());
    lw->AddActuator("DriveTrain", "Left 2 CIM", Left2MotorController.get());
    lw->AddActuator("DriveTrain", "Right 1 CIM", Right1MotorController.get());
    lw->AddActuator("DriveTrain", "Right 2 CIM", Right2MotorController.get());

	DriveTank->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	DriveTank->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	DriveTank->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	DriveTank->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::TankDrive(std::shared_ptr<Joystick> JoyStick)
{
	TankDrive(JoyStick->GetY(), JoyStick->GetRawAxis(3));
}

void DriveTrain::Stop()
{
	TankDrive(0.0, 0.0);
}

void DriveTrain::TankDrive(double leftSide, double rightSide)
{
	DriveTank->TankDrive(leftSide, rightSide, false);
}
