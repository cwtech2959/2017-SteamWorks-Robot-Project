/*
 * JoystickConditioning.h
 *
 *  Created on: Mar 29, 2017
 *      Author: Kevin
 */

#ifndef SRC_JOYSTICKCONDITIONING_H_
#define SRC_JOYSTICKCONDITIONING_H_

class JoystickConditioning
{
private:
	double m_negativeDeadband;
	double m_positiveDeadband;
	double m_negativeOffset;
	double m_positiveOffset;
	double m_lowInputGain;
	double m_scalar;

	double m_negativeIntermediate;
	double m_positiveIntermediate;

	void PreCalculations();

public:
	JoystickConditioning(double negativeDeadBand = -0.1, double positiveDeadband = 0.1,
			double negativeOffset = -0.1, double positiveOffset = 0.1,
			double lowInputGain = 1.0, double scalar = 1.0);
	virtual ~JoystickConditioning();

	void UpdateConstants(double negativeDeadBand = -0.1, double positiveDeadband = 0.1,
			double negativeOffset = -0.1, double positiveOffset = 0.1,
			double lowInputGain = 1.0, double scalar = 1.0);

	double Conditioned(double input) const;
};

#endif /* SRC_JOYSTICKCONDITIONING_H_ */
