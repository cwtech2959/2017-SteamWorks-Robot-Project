/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 28, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_DRIVEWITHJOYSTICK_H_
#define SRC_COMMANDS_DRIVEWITHJOYSTICK_H_

#include "WPILib.h"

class DriveWithJoystick: public Command
{
public:
	DriveWithJoystick();
	virtual ~DriveWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_DRIVEWITHJOYSTICK_H_ */
