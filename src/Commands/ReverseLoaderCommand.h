/*
 * LoadCommand.h
 *
 *  Created on: Jan 25, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_REVERSELOADERCOMMAND_H_
#define SRC_COMMANDS_REVERSELOADERCOMMAND_H_

#include <CommandBase.h>

class ReverseLoaderCommand: public CommandBase
{
public:
	ReverseLoaderCommand();
	virtual ~ReverseLoaderCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_REVERSELOADERCOMMAND_H_ */
