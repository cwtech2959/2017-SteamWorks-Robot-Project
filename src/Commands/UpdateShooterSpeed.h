/*
 * UpdateShooterSpeed.h
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#ifndef SRC_COMMANDS_UPDATESHOOTERSPEED_H_
#define SRC_COMMANDS_UPDATESHOOTERSPEED_H_

#include "WPILib.h"

class UpdateShooterSpeed: public Command
{
public:
	UpdateShooterSpeed();
	virtual ~UpdateShooterSpeed();

	void Initialize() override;
	bool IsFinished () override;
};

#endif /* SRC_COMMANDS_UPDATESHOOTERSPEED_H_ */
