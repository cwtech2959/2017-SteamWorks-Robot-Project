/*
 * Loader.h
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_LOADER_H_
#define SRC_SUBSYSTEMS_LOADER_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>

class Loader: public Subsystem
{
private:
	std::shared_ptr<Spark> LoaderConveyor;

public:
	Loader();
	virtual ~Loader();

	void StopLoaderConveyor();

	void ReverseLoaderConveyor();
	void LoaderConveyorForward();
};

#endif /* SRC_SUBSYSTEMS_LOADER_H_ */
