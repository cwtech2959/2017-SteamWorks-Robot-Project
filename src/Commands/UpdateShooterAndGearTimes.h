/*
 * UpdateShooterAndGearTimes.h
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_UPDATESHOOTERANDGEARTIMES_H_
#define SRC_COMMANDS_UPDATESHOOTERANDGEARTIMES_H_

#include <CommandBase.h>

class UpdateShooterAndGearTimes: public CommandBase {
public:
	UpdateShooterAndGearTimes();
	virtual ~UpdateShooterAndGearTimes();

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_UPDATESHOOTERANDGEARTIMES_H_ */
