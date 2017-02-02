/*
 * ShooterAndLoader.h
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_SHOOTERANDLOADER_H_
#define SRC_SUBSYSTEMS_SHOOTERANDLOADER_H_

#include <Commands/Subsystem.h>
#include "Spark.h"
#include "RobotMap.h"

class ShooterAndLoader: public frc::Subsystem
{
	// private members
private:
	frc::Spark ShooterConveyorRight
	{ SHOOTER_CONVEYOR_RIGHT_PWM };
	frc::Spark ShooterConveyorLeft
	{ SHOOTER_CONVEYOR_LEFT_PWM };
	frc::Spark LoaderConveyor
	{ LOADER_CONVEYOR_PWM };

	bool ShooterConveyorState;
	bool LoaderConveyorState;

	int StartOffSetRight;
	int StartOffSetLeft;
	int OnTime;
	int OffTime;

public:
	ShooterAndLoader();
	virtual ~ShooterAndLoader();

	void StopAllConveyors();
	void ToggleLoaderConveyor();
	void ToggleShooterConveyors();



private:
	void SetShooterConveyorSpeed(double speed);
};
#endif /* SRC_SUBSYSTEMS_SHOOTERANDLOADER_H_ */
