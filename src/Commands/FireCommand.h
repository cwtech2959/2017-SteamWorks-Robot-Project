/*
 * FireCommand.h
 *
 *  Created on: Jan 24, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_FIRECOMMAND_H_
#define SRC_COMMANDS_FIRECOMMAND_H_

#include <CommandBase.h>

class FireCommand: public CommandBase {
public:
	FireCommand();
	virtual ~FireCommand();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_FIRECOMMAND_H_ */

