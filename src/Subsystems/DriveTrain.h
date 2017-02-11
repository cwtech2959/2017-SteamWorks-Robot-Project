/*
 * DriveTrain.h
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include <Commands/Subsystem.h>
#include "Joystick.h"
#include "CanTalonSRX.h"
#include <CanRobotDrive.h>
#include <RobotMap.h>

class DriveTrain: public frc::Subsystem
{
private:

	CanTalonSRX Left1MotorController
	{ LEFT_DRIVE_MOTOR_1_CAN };
	CanTalonSRX Left2MotorController
	{ LEFT_DRIVE_MOTOR_2_CAN };
	CanTalonSRX Right1MotorController
	{ RIGHT_DRIVE_MOTOR_1_CAN };
	CanTalonSRX Right2MotorController
	{ RIGHT_DRIVE_MOTOR_2_CAN };

	CanRobotDrive DriveTank
	{
		&Left1MotorController,
		&Left2MotorController,
		&Right1MotorController,
		&Right2MotorController,
		false, true };

public:
	DriveTrain();
	virtual ~DriveTrain();

	void InitDefaultCommand() override;

	void TankDrive(double leftSide, double rightSide);
	void TankDrive(frc::Joystick * pJoyStick);
	void Stop();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
