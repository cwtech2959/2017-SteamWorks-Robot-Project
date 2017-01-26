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

public:
	ShooterAndLoader();
	virtual ~ShooterAndLoader();

	void StopAllConveyors();
	void StartLoaderConveyor();
	void StartShooterConveyors();
};
#endif /* SRC_SUBSYSTEMS_SHOOTERANDLOADER_H_ */
