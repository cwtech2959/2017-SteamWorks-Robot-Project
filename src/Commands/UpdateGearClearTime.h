/*
 * UpdateGearClearTime.h
 *
 *  Created on: Feb 16, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_UPDATEGEARCLEARTIME_H_
#define SRC_COMMANDS_UPDATEGEARCLEARTIME_H_

#include "WPILib.h"

class UpdateGearClearTime: public Command
{
public:
	UpdateGearClearTime();
	virtual ~UpdateGearClearTime();

	void Initialize() override;
	bool IsFinished () override;
};

#endif /* SRC_COMMANDS_UPDATEGEARCLEARTIME_H_ */
