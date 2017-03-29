/*
 * JoystickConditioning.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: Kevin
 */

#include <JoystickConditioning.h>

JoystickConditioning::JoystickConditioning(double negativeDeadBand, double positiveDeadband,
		double negativeOffset, double positiveOffset,
		double lowInputGain, double scalar)
{
	m_negativeDeadband = negativeDeadBand;
	m_positiveDeadband = positiveDeadband;
	m_negativeOffset = negativeOffset;
	m_positiveOffset = positiveOffset;
	m_lowInputGain = lowInputGain;
	m_scalar = scalar;
	PreCalculations();
}

JoystickConditioning::~JoystickConditioning()
{
}

void JoystickConditioning::PreCalculations()
{
	double gPos = m_positiveDeadband * (-m_lowInputGain * m_positiveDeadband * m_positiveDeadband - 1 + m_lowInputGain);
	double gNeg = m_negativeDeadband * (-m_lowInputGain * m_negativeDeadband * m_negativeDeadband - 1 + m_lowInputGain);

	m_positiveIntermediate = (m_positiveOffset / m_scalar + gPos) / (1 + gPos);
	m_negativeIntermediate = (m_negativeOffset / m_scalar + gNeg) / (1 - gNeg);
}

double JoystickConditioning::Conditioned(double input) const
{
	double output = 0;
	if (input > m_positiveDeadband)
	{
		output = m_positiveIntermediate + (1 - m_positiveIntermediate) * input * (m_lowInputGain * input * input + 1 - m_lowInputGain);
	}
	else if (input < m_negativeDeadband)
	{
		output = m_negativeIntermediate + (1 + m_negativeIntermediate) * input * (m_lowInputGain * input * input + 1 - m_lowInputGain);
	}

	return m_scalar * output;
}
