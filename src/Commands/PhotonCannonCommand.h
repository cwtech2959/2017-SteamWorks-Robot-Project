/*
 * TogglePhotonCannonCommand.h
 *
 *  Created on: Jan 28, 2017
 *      Author: jlsch
 */

#ifndef SRC_COMMANDS_PHOTONCANNONCOMMAND_H_
#define SRC_COMMANDS_PHOTONCANNONCOMMAND_H_

#include <CommandBase.h>

class PhotonCannonCommand: public CommandBase
{
public:
	PhotonCannonCommand();
	virtual ~PhotonCannonCommand();

	void Execute() override;
	bool IsFinished() override;
	void End() override;
};

#endif /* SRC_COMMANDS_PHOTONCANNONCOMMAND_H_ */
