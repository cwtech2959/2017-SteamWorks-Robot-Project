/*
 * TogglePhotonCannonCommand.h
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#ifndef SRC_COMMANDS_PHOTONCANNONONCOMMAND_H_
#define SRC_COMMANDS_PHOTONCANNONONCOMMAND_H_

#include "WPILib.h"

class PhotonCannonOnCommand: public Command
{
public:
	PhotonCannonOnCommand();
	virtual ~PhotonCannonOnCommand();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_PHOTONCANNONONCOMMAND_H_ */
