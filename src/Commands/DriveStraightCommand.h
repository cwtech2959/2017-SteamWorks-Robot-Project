/*
 * DriveStraight.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#ifndef SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_
#define SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_

#include "WPILib.h"

class DriveStraightCommand: public Command
{
public:
	DriveStraightCommand();
	virtual ~DriveStraightCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_ */
