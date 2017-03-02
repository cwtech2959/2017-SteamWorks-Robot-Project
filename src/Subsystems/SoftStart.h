/*
 * SoftStart.h
 *
 *  Created on: Feb 27, 2017
 *      Author: mriri
 */

#ifndef SRC_SUBSYSTEMS_SOFTSTART_H_
#define SRC_SUBSYSTEMS_SOFTSTART_H_

class SoftStart
{
public:
	SoftStart(double rampTimeMs, double loopTimeMs = 20);
	virtual ~SoftStart();

	void SetTargetSpeed(double targetSpeed, double currentSpeed);
	double NextSpeed();

private:
	double m_targetSpeed;
	double m_rampRate;
	double m_rampTime;
	double m_loopTime;
	double m_currentSpeed;
};

#endif /* SRC_SUBSYSTEMS_SOFTSTART_H_ */
