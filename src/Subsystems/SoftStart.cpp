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

double SoftStart::NextSpeed(double targetSpeed)
{
	if (m_currentSpeed > targetSpeed)
	{
		m_currentSpeed -= m_rampDownRate;
		if (m_currentSpeed > targetSpeed)
		{
			return m_currentSpeed;
		}
		else
		{
			return targetSpeed;
		}
	}
	else
	{
		m_currentSpeed += m_rampUpRate;
		if (m_currentSpeed < targetSpeed)
		{
			return m_currentSpeed;
		}
		else
		{
			return targetSpeed;
		}
	}
}
