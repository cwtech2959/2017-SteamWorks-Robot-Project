/*
 * FryingPanUpCommand.h
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_FRYINGPANUPCOMMAND_H_
#define SRC_COMMANDS_FRYINGPANUPCOMMAND_H_

#include "WPILib.h"

class FryingPanUpCommand: public Command
{
public:
	FryingPanUpCommand(bool up);
	virtual ~FryingPanUpCommand();

public:
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	bool m_up;
};

#endif /* SRC_COMMANDS_FRYINGPANUPCOMMAND_H_ */
