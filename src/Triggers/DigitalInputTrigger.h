/*
 * DigitalInputTrigger.h
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#ifndef SRC_DIGITALINPUTTRIGGER_H_
#define SRC_DIGITALINPUTTRIGGER_H_

#include "WPILib.h"

class DigitalInputTrigger: public Trigger
{
public:
	DigitalInputTrigger(std::shared_ptr<DigitalInput> digitalInput);
	virtual ~DigitalInputTrigger();

	bool Get() override;

private:
	std::shared_ptr<DigitalInput> m_digitalInput;
};

#endif /* SRC_DIGITALINPUTTRIGGER_H_ */
