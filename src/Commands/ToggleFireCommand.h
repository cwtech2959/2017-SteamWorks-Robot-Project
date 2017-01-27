/*
 * FireCommand.h
 *
 *  Created on: Jan 24, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_TOGGLEFIRECOMMAND_H_
#define SRC_COMMANDS_TOGGLEFIRECOMMAND_H_

#include <CommandBase.h>

class ToggleFireCommand: public CommandBase
{
public:
	ToggleFireCommand();
	virtual ~ToggleFireCommand();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_TOGGLEFIRECOMMAND_H_ */

