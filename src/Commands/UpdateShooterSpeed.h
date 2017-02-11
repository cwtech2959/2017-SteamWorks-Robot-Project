/*
 * UpdateShooterSpeed.h
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_UPDATESHOOTERSPEED_H_
#define SRC_COMMANDS_UPDATESHOOTERSPEED_H_

#include <CommandBase.h>

class UpdateShooterSpeed: public CommandBase {
public:
	UpdateShooterSpeed();
	virtual ~UpdateShooterSpeed();

	void Initialize() override;
	bool IsFinished () override;
};

#endif /* SRC_COMMANDS_UPDATESHOOTERSPEED_H_ */
