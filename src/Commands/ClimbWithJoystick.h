/*
 * ClimbWithJoystick.h
 *
 *  Created on: Apr 1, 2017
 *      Author:
 */

#ifndef SRC_COMMANDS_CLIMBWITHJOYSTICK_H_
#define SRC_COMMANDS_CLIMBWITHJOYSTICK_H_

#include "WPILib.h"

class ClimbWithJoystick: public Command
{
public:
	ClimbWithJoystick();
	virtual ~ClimbWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_CLIMBWITHJOYSTICK_H_ */
