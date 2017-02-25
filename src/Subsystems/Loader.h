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

constexpr int DefaultClearTime = 100;

class Loader: public Subsystem
{
private:
	std::shared_ptr<Spark> BallPickupAndAgitator;

	int GearClearTime;

public:
	Loader();
	virtual ~Loader();

	void StopBallLoader();

	void ReverseBallLoader();
	void BallLoaderForward();

	int GetGearClearTime();
	void SetGearClearTime(int time);
};

#endif /* SRC_SUBSYSTEMS_LOADER_H_ */
