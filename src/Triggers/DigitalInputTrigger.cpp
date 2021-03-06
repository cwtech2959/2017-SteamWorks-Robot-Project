/*
 * DigitalInputTrigger.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#include <Triggers/DigitalInputTrigger.h>

DigitalInputTrigger::DigitalInputTrigger(std::shared_ptr<DigitalInput> digitalInput)
{
	m_digitalInput = digitalInput;
}

DigitalInputTrigger::~DigitalInputTrigger()
{
}

bool DigitalInputTrigger::Get()
{
	return m_digitalInput->Get();
}
