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
	SoftStart(double rampUpTimeMs, double rampDownTimeMs, double loopTimeMs = 20);
	virtual ~SoftStart();

	double CurrentSpeed() const;
	double NextSpeed(double targetSpeed);

private:
	double m_rampUpRate;
	double m_rampDownRate;
	double m_currentSpeed;
};

#endif /* SRC_SUBSYSTEMS_SOFTSTART_H_ */
