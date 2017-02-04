/*
 * StartFireSequenceCommand.h
 *
 *  Created on: Feb 3, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_STARTFIRESEQUENCECOMMAND_H_
#define SRC_COMMANDS_STARTFIRESEQUENCECOMMAND_H_

#include <CommandBase.h>

class StartFireSequenceCommand: public CommandBase
{
public:
	StartFireSequenceCommand();
	virtual ~StartFireSequenceCommand();

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_STARTFIRESEQUENCECOMMAND_H_ */
