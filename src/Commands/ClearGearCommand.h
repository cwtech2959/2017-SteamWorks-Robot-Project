/*
 * ClearGearCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_CLEARGEARCOMMAND_H_
#define SRC_COMMANDS_CLEARGEARCOMMAND_H_

#include <CommandBase.h>

class ClearGearCommand: public CommandBase
{
public:
	ClearGearCommand();
	virtual ~ClearGearCommand();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool m_gearGone;
};

#endif /* SRC_COMMANDS_CLEARGEARCOMMAND_H_ */
