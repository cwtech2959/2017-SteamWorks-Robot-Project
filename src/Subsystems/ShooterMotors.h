/*
 * ShooterMotors.h
 *
 *  Created on: Feb 24, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_SHOOTERMOTORS_H_
#define SRC_SUBSYSTEMS_SHOOTERMOTORS_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <CANTalon.h>

constexpr double DefaultShooterSpeed = 0.65;

class ShooterMotors: public Subsystem
{
private:
	std::shared_ptr<CANTalon> BallShooterLeft;
	std::shared_ptr<CANTalon> BallShooterRight;

public:
	ShooterMotors();
	virtual ~ShooterMotors();

	void SetBallShootersSpeed(double speed);
};

#endif /* SRC_SUBSYSTEMS_SHOOTERMOTORS_H_ */
