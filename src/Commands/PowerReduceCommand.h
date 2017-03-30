/*
 * PowerReduceCommand.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#ifndef SRC_COMMANDS_POWERREDUCECOMMAND_H_
#define SRC_COMMANDS_POWERREDUCECOMMAND_H_

#include "WPILib.h"

class PowerReduceCommand: public Command
{
public:
	PowerReduceCommand();
	virtual ~PowerReduceCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_POWERREDUCECOMMAND_H_ */
