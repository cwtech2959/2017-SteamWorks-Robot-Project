/*
 * InvertTankCommand.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Eva
 */

#ifndef SRC_COMMANDS_INVERTTANKCOMMAND_H_
#define SRC_COMMANDS_INVERTTANKCOMMAND_H_

#include "WPILib.h"

class InvertTankCommand: public Command
{
public:
	InvertTankCommand();
	virtual ~InvertTankCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_INVERTTANKCOMMAND_H_ */
