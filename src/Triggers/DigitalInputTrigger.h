/*
 * DigitalInputTrigger.h
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#ifndef SRC_DIGITALINPUTTRIGGER_H_
#define SRC_DIGITALINPUTTRIGGER_H_

#include <Buttons/Trigger.h>
#include <DigitalInput.h>

class DigitalInputTrigger: public frc::Trigger
{
public:
	DigitalInputTrigger(frc::DigitalInput * digitalInput);
	virtual ~DigitalInputTrigger();

	bool Get() override;

private:
	frc::DigitalInput * m_digitalInput;
};

#endif /* SRC_DIGITALINPUTTRIGGER_H_ */
