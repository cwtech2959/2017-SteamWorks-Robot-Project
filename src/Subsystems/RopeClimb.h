/*
 * Climb.h
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#ifndef SRC_SUBSYSTEMS_ROPECLIMB_H_
#define SRC_SUBSYSTEMS_ROPECLIMB_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class RopeClimb: public Subsystem
{
private:
	std::shared_ptr<CANTalon> ClimbRightMotor;
	std::shared_ptr<CANTalon> ClimbLeftMotor;

public:
	RopeClimb();
	virtual ~RopeClimb();

	void InitDefaultCommand() override;

	void Climb(std::shared_ptr<Joystick> JoyStick);
};

#endif /* SRC_SUBSYSTEMS_ROPECLIMB_H_ */
