/*
 * LoadCommand.h
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_LOADCOMMAND_H_
#define SRC_COMMANDS_LOADCOMMAND_H_

#include <CommandBase.h>

class LoadCommand: public CommandBase
{
public:
	LoadCommand();
	virtual ~LoadCommand();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_LOADCOMMAND_H_ */
