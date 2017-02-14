/*
 * DriveTrain.h
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include <Commands/Subsystem.h>
#include <Joystick.h>
#include <CANTalon.h>
#include <RobotDrive.h>

class DriveTrain: public frc::Subsystem
{
private:
	CANTalon Left1MotorController
	{ 5 };
	CANTalon Left2MotorController
	{ 6 };
	CANTalon Right1MotorController
	{ 1 };
	CANTalon Right2MotorController
	{ 2 };

	frc::RobotDrive DriveTank
	{
		&Left1MotorController,
		&Left2MotorController,
		&Right1MotorController,
		&Right2MotorController
	};

public:
	DriveTrain();
	virtual ~DriveTrain();

	void InitDefaultCommand() override;

	void TankDrive(double leftSide, double rightSide);
	void TankDrive(frc::Joystick * pJoyStick);
	void Stop();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
