/*
 * MaintainLoaderSpeed.h
 *
 *  Created on: Mar 6, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_MAINTAINLOADERSPEED_H_
#define SRC_COMMANDS_MAINTAINLOADERSPEED_H_

#include "WPILib.h"

class MaintainLoaderSpeed: public Command
{
public:
	MaintainLoaderSpeed();
	virtual ~MaintainLoaderSpeed();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_MAINTAINLOADERSPEED_H_ */
