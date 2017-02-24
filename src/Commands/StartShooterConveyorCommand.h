/*
 * StartShootConveyor.h
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_STARTSHOOTERCONVEYORCOMMAND_H_
#define SRC_COMMANDS_STARTSHOOTERCONVEYORCOMMAND_H_

#include "WPILib.h"
#include <Subsystems/Shooter.h>

class StartShooterConveyorCommand: public Command
{
public:
	StartShooterConveyorCommand(Shooter::ShooterSide side);
	virtual ~StartShooterConveyorCommand();

	void Initialize() override;
	void End() override;
	void Interrupted() override;
	bool IsFinished() override;

private:
	Shooter::ShooterSide m_shooterSide;
};

#endif /* SRC_COMMANDS_STARTSHOOTERCONVEYORCOMMAND_H_ */
