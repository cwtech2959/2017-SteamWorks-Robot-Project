/*
 * PhotonCannonSubsystem.h
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#ifndef SRC_SUBSYSTEMS_PHOTONCANNON_H_
#define SRC_SUBSYSTEMS_PHOTONCANNON_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>

class PhotonCannon: public Subsystem
{
private:
	std::shared_ptr<Spark> LightController;

public:
	PhotonCannon();
	virtual ~PhotonCannon();

	void LightOff();
	void LightOn();
};

#endif /* SRC_SUBSYSTEMS_PHOTONCANNON_H_ */
