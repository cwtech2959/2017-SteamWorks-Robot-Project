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
#include <Subsystems/SoftStart.h>

constexpr double DefaultClearTime = 100;

class Loader: public Subsystem
{
private:
	std::shared_ptr<Spark> BallPickupAndAgitator;

	double GearClearTime;
	double m_loaderTargetSpeed;

	void SetBallLoadersSpeed(double speed);

	SoftStart rampPickup {300, 300};

public:
	Loader();
	virtual ~Loader();

	void InitDefaultCommand() override;

	void ReverseBallLoader();
	void BallLoaderForward();

	double GetGearClearTime();
	void SetGearClearTime(double time);

	void MaintainLoader();
};

#endif /* SRC_SUBSYSTEMS_LOADER_H_ */
