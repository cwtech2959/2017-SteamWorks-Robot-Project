/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#include <Subsystems/DriveTrain.h>
#include <Commands/DriveWithJoystick.h>
#include <RobotMap.h>
#include <Utilities.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_DriveStraight = false;
	m_PowerReduction = false;
	m_InvertTank = false;

	InitHardware();
}

DriveTrain::~DriveTrain()
{
}

void DriveTrain::InitHardware()
{
	Left1MotorController.reset(new CANTalon(LEFT_DRIVE_MOTOR_1_CAN));
	Left2MotorController.reset(new CANTalon(LEFT_DRIVE_MOTOR_2_CAN));
	Right1MotorController.reset(new CANTalon(RIGHT_DRIVE_MOTOR_1_CAN));
	Right2MotorController.reset(new CANTalon(RIGHT_DRIVE_MOTOR_2_CAN));

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
	DriveTank->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	DriveTank->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::TankDrive(std::shared_ptr<Joystick> JoyStick)
{
	double leftSide = LeftConditioning.Conditioned(JoyStick->GetY());
	double rightSide = RightConditioning.Conditioned(JoyStick->GetRawAxis(3));

	// Need to limit output, if power reduce
	if (m_PowerReduction == true)
	{
		leftSide = Limit(leftSide, -MaxReducedPower, MaxReducedPower);
		rightSide = Limit(rightSide, -MaxReducedPower, MaxReducedPower);
	}

	// Force invert tank direction, if needed
	if (m_InvertTank == true)
	{
		double temp = leftSide;
		leftSide = -1 * rightSide;
		rightSide = -1 * temp;
	}

	// Force drive straight, if needed
	// Mirror rightSide input to equal left side input
	if (m_DriveStraight == true)
	{
		rightSide = leftSide;
	}

	TankDrive(leftSide, rightSide);
}

void DriveTrain::Stop()
{
	TankDrive(0.0, 0.0);
}

void DriveTrain::TankDrive(double leftSide, double rightSide)
{
	// soft start to drive motors
	leftSide = LeftSideSpeedRamping.NextSpeed(leftSide);
	rightSide = RightSideSpeedRamping.NextSpeed(rightSide);

	DriveTank->TankDrive(leftSide, rightSide, false);
}

void DriveTrain::SetInvertTank(bool invert)
{
	m_InvertTank = invert;
}

void DriveTrain::SetDriveStraight(bool straight)
{
	m_DriveStraight = straight;
}

void DriveTrain::SetPowerReduction(bool reduce)
{
	m_PowerReduction = reduce;
}
