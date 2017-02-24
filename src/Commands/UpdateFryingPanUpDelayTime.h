/*
 * UpdateFryingPanUpDelayTime.h
 *
 *  Created on: Feb 20, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_UPDATEFRYINGPANUPDELAYTIME_H_
#define SRC_COMMANDS_UPDATEFRYINGPANUPDELAYTIME_H_

#include "WPILib.h"

class UpdateFryingPanUpDelayTime: public Command
{
public:
	UpdateFryingPanUpDelayTime();
	virtual ~UpdateFryingPanUpDelayTime();

	void Initialize() override;
	bool IsFinished () override;
};

#endif /* SRC_COMMANDS_UPDATEFRYINGPANUPDELAYTIME_H_ */
