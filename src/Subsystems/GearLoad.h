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
#include <CANTalon.h>

constexpr int DefaultClearTime = 500;

class GearLoad: public frc::Subsystem {
private:
	std::shared_ptr<DigitalInput> GearLoadReady;

	std::shared_ptr<CANTalon> GearPickup;

	int GearClearTime;

public:
	GearLoad();
	virtual ~GearLoad();

	bool GetGearLoadReady();
	void SetGearClearTime(int time);
};

#endif /* SRC_SUBSYSTEMS_GEARLOAD_H_ */
