/*
 * ClearGearCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_CLEARGEARCOMMAND_H_
#define SRC_COMMANDS_CLEARGEARCOMMAND_H_

#include "WPILib.h"

class ClearGearCommand: public Command
{
public:
	ClearGearCommand();
	virtual ~ClearGearCommand();

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool m_gearGone;
};

#endif /* SRC_COMMANDS_CLEARGEARCOMMAND_H_ */
