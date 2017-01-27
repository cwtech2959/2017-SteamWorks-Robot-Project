/*
 * LoadCommand.h
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_TOGGLELOADCOMMAND_H_
#define SRC_COMMANDS_TOGGLELOADCOMMAND_H_

#include <CommandBase.h>

class ToggleLoadCommand: public CommandBase
{
public:
	ToggleLoadCommand();
	virtual ~ToggleLoadCommand();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_TOGGLELOADCOMMAND_H_ */
