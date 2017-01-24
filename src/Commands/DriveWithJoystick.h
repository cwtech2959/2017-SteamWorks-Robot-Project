/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 21, 2017
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_DRIVEWITHJOYSTICK_H_
#define SRC_COMMANDS_DRIVEWITHJOYSTICK_H_

#include <CommandBase.h>

class DriveWithJoystick: public CommandBase
{
public:
	DriveWithJoystick();
	virtual ~DriveWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_DRIVEWITHJOYSTICK_H_ */
