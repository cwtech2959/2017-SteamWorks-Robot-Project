/*
 * PhotonCannonSubsystem.h
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#ifndef SRC_SUBSYSTEMS_PHOTONCANNONSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_PHOTONCANNONSUBSYSTEM_H_

#include <Spark.h>
#include <Commands/Subsystem.h>

class PhotonCannonSubsystem: public frc::Subsystem
{
private:
	frc::Spark LightController {7};

public:
	PhotonCannonSubsystem();
	virtual ~PhotonCannonSubsystem();

	void LightOff();
	void LightOn();
};

#endif /* SRC_SUBSYSTEMS_PHOTONCANNONSUBSYSTEM_H_ */
