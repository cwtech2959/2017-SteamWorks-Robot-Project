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
	UpdateConstants( negativeDeadBand, positiveDeadband,
			negativeOffset, positiveOffset,
			lowInputGain, scalar);
}

JoystickConditioning::~JoystickConditioning()
{
}

void JoystickConditioning::UpdateConstants(double negativeDeadBand, double positiveDeadband,
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

//
// Calculation, frpm 2013 spec
//	g(z)=
//		{0,
//		c<z<a f*[b/f-ea3-a+ea1-ea3-a+ea+ [1-b/f-ea3-a+ae1-ea3-a+ae]*[ez3 + (1-e)z]],
//		z≥a f*[d/f-ec3-c+ec1+ec3+c-ec+ [1+d/f-ec3-c+ec1+ec3+c-ec]*[ez3 + (1-e)z]],
//		z≤c
//
//  z = input
//  p = if z > deadband then 1 else -1
//	g = deadband * ( -gain * deadband * deadband -1 + gain)
//  partial pre-calculation h = (offset / scalar + g) / (1 + g * p)
//  output = scalar * (h + (1 - p * h) * (gain * z**3 + (1 - gain) * z))

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
