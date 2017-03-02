/*
 * FryingPanUpCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_MOVEFRYINGPANCOMMAND_H_
#define SRC_COMMANDS_MOVEFRYINGPANCOMMAND_H_

#include "WPILib.h"

class MoveFryingPanCommand: public Command
{
public:
	MoveFryingPanCommand(bool up);
	virtual ~MoveFryingPanCommand();

public:
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool m_up;
};

#endif /* SRC_COMMANDS_MOVEFRYINGPANCOMMAND_H_ */
