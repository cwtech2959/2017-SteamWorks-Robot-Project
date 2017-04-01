/*
 * GearLoad.h
 *
 *  Created on: Feb 24, 2017
 *      Author: mriri
 */

#ifndef SRC_SUBSYSTEMS_GEARLOAD_H_
#define SRC_SUBSYSTEMS_GEARLOAD_H_

#include <Commands/Subsystem.h>
#include "WPILib.h"

class GearLoad: public Subsystem
{
private:
	std::shared_ptr<DigitalInput> GearLoadReady;

	std::shared_ptr<Spark> GearPickup;

public:
	GearLoad();
	virtual ~GearLoad();

	bool GetGearLoadReady();

	void Stop();
	void LoadGear();
};

#endif /* SRC_SUBSYSTEMS_GEARLOAD_H_ */
