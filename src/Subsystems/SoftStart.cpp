/*
 * SoftStart.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: mriri
 */

#include <Subsystems/SoftStart.h>
#include <cmath>
#include <algorithm>

SoftStart::SoftStart(double rampUpTimeMs, double rampDownTimeMs, double loopTimeMs)
{
	m_rampUpRate = loopTimeMs / std::max(rampUpTimeMs, loopTimeMs);
	m_rampDownRate = loopTimeMs / std::max(rampUpTimeMs, loopTimeMs);
	m_currentSpeed = 0;
}

SoftStart::~SoftStart()
{
}

double SoftStart::CurrentSpeed() const
{
	return m_currentSpeed;
}

double SoftStart::NextSpeed(double targetSpeed)
{
	double nextSpeed = m_currentSpeed;
	if (nextSpeed > targetSpeed)
	{
		nextSpeed -= m_rampDownRate;
		if (nextSpeed < targetSpeed)
		{
			nextSpeed = targetSpeed;
		}
	}
	else
	{
		nextSpeed += m_rampUpRate;
		if (nextSpeed > targetSpeed)
		{
			nextSpeed = m_currentSpeed;
		}
	}

	m_currentSpeed = nextSpeed;
	return nextSpeed;
}
