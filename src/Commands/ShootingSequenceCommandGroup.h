/*
 * ShootingSequenceCommandGroup.h
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_SHOOTINGSEQUENCECOMMANDGROUP_H_
#define SRC_COMMANDS_SHOOTINGSEQUENCECOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <Subsystems/Shooter.h>

class ShootingSequenceCommandGroup: public frc::CommandGroup
{
public:
	ShootingSequenceCommandGroup(Shooter::ShooterSide side);
	virtual ~ShootingSequenceCommandGroup();
};

#endif /* SRC_COMMANDS_SHOOTINGSEQUENCECOMMANDGROUP_H_ */
