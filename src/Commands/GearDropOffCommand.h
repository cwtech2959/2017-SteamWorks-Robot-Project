/*
 * GearDropOffCommand.h
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_GEARDROPOFFCOMMAND_H_
#define SRC_COMMANDS_GEARDROPOFFCOMMAND_H_

#include <CommandBase.h>

class GearDropOffCommand: public CommandBase
{
public:
	GearDropOffCommand();
	virtual ~GearDropOffCommand();

	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_GEARDROPOFFCOMMAND_H_ */
