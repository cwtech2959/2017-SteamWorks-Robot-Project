/*
 * ParallelShootingCommandGroup.h
 *
 *  Created on: Feb 4, 2017
 *      Author: CW
 */

#ifndef SRC_COMMANDS_PARALLELSHOOTINGCOMMANDGROUP_H_
#define SRC_COMMANDS_PARALLELSHOOTINGCOMMANDGROUP_H_

#include "WPILib.h"

class ParallelShootingCommandGroup: public CommandGroup
{
public:
	ParallelShootingCommandGroup();
	virtual ~ParallelShootingCommandGroup();

	void Initialize() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_PARALLELSHOOTINGCOMMANDGROUP_H_ */
