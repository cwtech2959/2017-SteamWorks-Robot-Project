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

class ShooterAndLoader: public frc::Subsystem
{
	// private members
private:
	frc::Spark ShooterConveyorRight
	{ 4 };
	frc::Spark ShooterConveyorLeft
	{ 5 };
	frc::Spark LoaderConveyor
	{ 6 };

	bool ShooterConveyorState;
	bool LoaderConveyorState;

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
