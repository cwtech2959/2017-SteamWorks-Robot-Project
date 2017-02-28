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
	SoftStart(double rampTimeMs);
	virtual ~SoftStart();

	void SetTargetSpeed(double targetSpeed);
	double SoftStartedSpeed(double currentSpeed);

private:
	double m_targetSpeed;
	double m_rampRate;
	double m_rampTime;
};

#endif /* SRC_SUBSYSTEMS_SOFTSTART_H_ */
