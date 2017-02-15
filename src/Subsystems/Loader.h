/*
 * Loader.h
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_LOADER_H_
#define SRC_SUBSYSTEMS_LOADER_H_

#include <Commands/Subsystem.h>

#include "Spark.h"
#include "RobotMap.h"


class Loader: public frc::Subsystem {
private:
	frc::Spark LoaderConveyor
		{ LOADER_CONVEYOR_PWM };


public:
	Loader();
	virtual ~Loader();

void StopLoaderConveyor();

void ReverseLoaderConveyor();
void LoaderConveyorForward();



};

#endif /* SRC_SUBSYSTEMS_LOADER_H_ */
