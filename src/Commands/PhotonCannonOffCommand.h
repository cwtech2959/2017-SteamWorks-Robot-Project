/*
 * PhotonCannonCommand2.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_PHOTONCANNONOFFCOMMAND_H_
#define SRC_COMMANDS_PHOTONCANNONOFFCOMMAND_H_

#include "WPILib.h"

class PhotonCannonOffCommand: public Command
{
public:
	PhotonCannonOffCommand();
	virtual ~PhotonCannonOffCommand();
	
	void Execute() override;
	bool IsFinished() override;
};


#endif /* SRC_COMMANDS_PHOTONCANNONOFFCOMMAND_H_ */
