/*
 * DigitalInputTrigger.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: CW
 */

#include <DigitalInputTrigger.h>

DigitalInputTrigger::DigitalInputTrigger(frc::DigitalInput digitalInput)
{
	m_digitalInput = digitalInput;
}

DigitalInputTrigger::~DigitalInputTrigger() {
}

bool DigitalInputTrigger::Get()
{
	return m_digitalInput;
}
