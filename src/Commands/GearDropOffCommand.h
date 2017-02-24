/*
 * GearDropOffCommand.h
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_GEARDROPOFFCOMMAND_H_
#define SRC_COMMANDS_GEARDROPOFFCOMMAND_H_

#include "WPILib.h"

class GearDropOffCommand: public Command
{
public:
	GearDropOffCommand(bool open);
	virtual ~GearDropOffCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool m_open;
};

#endif /* SRC_COMMANDS_GEARDROPOFFCOMMAND_H_ */
