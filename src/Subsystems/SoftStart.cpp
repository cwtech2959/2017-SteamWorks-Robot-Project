/*
 * SoftStart.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: mriri
 */

#include <Subsystems/SoftStart.h>
#include <cmath>

SoftStart::SoftStart(double rampTimeMs, double loopTimeMs)
{
	m_rampTime = rampTimeMs;
	m_loopTime = loopTimeMs;
	m_targetSpeed = 0;
	m_rampRate = 0;
	m_currentSpeed = 0;
}

SoftStart::~SoftStart()
{
}

void SoftStart::SetTargetSpeed(double targetSpeed, double currentSpeed)
{
	m_currentSpeed = currentSpeed;
	m_targetSpeed = targetSpeed;
	double ramps = m_rampTime / m_loopTime;
	m_rampRate = fabs(targetSpeed - currentSpeed) / ramps;
}

double SoftStart::NextSpeed()
{
	if (m_currentSpeed > m_targetSpeed)
	{
		m_currentSpeed -= m_rampRate;
		if (m_currentSpeed > m_targetSpeed)
		{
			return m_currentSpeed;
		}
		else
		{
			return m_targetSpeed;
		}
	}
	else
	{
		m_currentSpeed += m_rampRate;
		if (m_currentSpeed < m_targetSpeed)
		{
			return m_currentSpeed;
		}
		else
		{
			return m_targetSpeed;
		}
	}
}
