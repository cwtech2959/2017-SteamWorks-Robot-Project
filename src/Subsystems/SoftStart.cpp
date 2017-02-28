/*
 * SoftStart.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: mriri
 */

#include <Subsystems/SoftStart.h>

SoftStart::SoftStart(double rampTimeMs)
{
	m_rampTime = rampTimeMs;
	m_targetSpeed = 0;
	m_rampRate = 0;
}

SoftStart::~SoftStart()
{

}

void SoftStart::SetTargetSpeed(double targetSpeed)
{
	m_targetSpeed = targetSpeed;
	double ramps = (m_rampTime/20);
	m_rampRate = (m_targetSpeed/ramps);
}

double SoftStart::SoftStartedSpeed(double currentSpeed)
{
	if (currentSpeed > m_targetSpeed)
	{
		currentSpeed -= m_rampRate;
		if (currentSpeed > m_targetSpeed)
		{
			return currentSpeed;
		}
		else
		{
			return m_targetSpeed;
		}
	}
	else
	{
		currentSpeed += m_rampRate;
		if (currentSpeed < m_targetSpeed)
		{
			return currentSpeed;
		}
		else
		{
			return m_targetSpeed;
		}
	}
}
