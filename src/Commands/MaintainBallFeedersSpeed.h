/*
 * MaintainShooterSpeed.h
 *
 *  Created on: Mar 3, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_MAINTAINBALLFEEDERSSPEED_H_
#define SRC_COMMANDS_MAINTAINBALLFEEDERSSPEED_H_

#include <Commands/Command.h>

class MaintainBallFeedersSpeed: public frc::Command
{
public:
	MaintainBallFeedersSpeed();
	virtual ~MaintainBallFeedersSpeed();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_MAINTAINBALLFEEDERSSPEED_H_ */
