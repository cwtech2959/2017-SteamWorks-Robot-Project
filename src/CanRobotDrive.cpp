/*
 * CanRobotDrive.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: mriri
 */

#include <CanRobotDrive.h>

CanRobotDrive::CanRobotDrive(CanTalonSRX * leftMotor1,
		CanTalonSRX * leftMotor2,
		CanTalonSRX * rightMotor1,
		CanTalonSRX * rightMotor2,
		bool invertLeftSide, bool invertRightSide)
{
	InitRobotDrive(leftMotor1, leftMotor2,
			NULL,
			rightMotor1,
			rightMotor2,
			NULL,
			invertLeftSide,
			invertRightSide);
}
CanRobotDrive::CanRobotDrive(CanTalonSRX * leftMotor1,
			CanTalonSRX * leftMotor2,
			CanTalonSRX * leftMotor3,
			CanTalonSRX * rightMotor1,
			CanTalonSRX * rightMotor2,
			CanTalonSRX * rightMotor3,
			bool invertLeftSide, bool invertRightSide)
{
	InitRobotDrive(leftMotor1, leftMotor2,
			leftMotor3,
			rightMotor1,
			rightMotor2,
			rightMotor3,
			invertLeftSide,
			invertRightSide);
}

CanRobotDrive::~CanRobotDrive()
{
	delete m_safetyHelper;
}

void CanRobotDrive::TankDrive(double leftSide, double rightSide)
{
	leftSide = Limit(leftSide);
	rightSide = Limit(rightSide);

	if (m_invertLeftSide)
	{
		leftSide = -1 * leftSide;
	}

	if (m_invertRightSide)
	{
		rightSide = -1 * rightSide;
	}

	if (m_leftMotor1 != NULL)
	{
		m_leftMotor1->Set(leftSide);
	}
	if (m_leftMotor2 != NULL)
	{
		m_leftMotor2->Set(leftSide);
	}
	if (m_leftMotor3 != NULL)
	{
		m_leftMotor3->Set(leftSide);
	}
	if (m_rightMotor1 != NULL)
	{
		m_rightMotor1->Set(rightSide);
	}
	if (m_rightMotor2 != NULL)
	{
		m_rightMotor2->Set(rightSide);
	}
	if (m_rightMotor3 != NULL)
	{
		m_rightMotor3->Set(rightSide);
	}

	m_safetyHelper->Feed();
}


void CanRobotDrive::SetExpiration(double timeout)
{
	m_safetyHelper->SetExpiration(timeout);
}

double CanRobotDrive::GetExpiration() const
{
	return m_safetyHelper->GetExpiration();
}
bool CanRobotDrive::IsAlive() const
{
	return m_safetyHelper->IsAlive();
}
void CanRobotDrive::StopMotor()
{
	TankDrive(0, 0);
}
bool CanRobotDrive::IsSafetyEnabled() const
{
	return m_safetyHelper->IsSafetyEnabled();
}
void CanRobotDrive::SetSafetyEnabled(bool enabled)
{
	m_safetyHelper->SetSafetyEnabled(enabled);
}
void CanRobotDrive::GetDescription(std::ostringstream& desc) const
{
	desc.str("CanRobotDrive");
}

int CanRobotDrive::GetNumMotors()
{
	int motors = 0;
	if (m_leftMotor1)
		motors++;
	if (m_leftMotor2)
			motors++;
	if (m_leftMotor3)
			motors++;
	if (m_rightMotor1)
			motors++;
	if (m_rightMotor2)
			motors++;
	if (m_rightMotor3)
		motors++;
	return motors;
}

double CanRobotDrive::Limit(double num)
{
	if (num > 1)
	{
		num = 1;
	}
	else if (num < -1)
	{
		num = -1;
	}

	return num;
}

void CanRobotDrive::InitRobotDrive(CanTalonSRX * leftMotor1,
		CanTalonSRX * leftMotor2,
		CanTalonSRX * leftMotor3,
		CanTalonSRX * rightMotor1,
		CanTalonSRX * rightMotor2,
		CanTalonSRX * rightMotor3,
		bool invertleftSide, bool invertrightSide)
{
	m_leftMotor1.reset(leftMotor1);
	m_leftMotor2.reset(leftMotor2);
	m_leftMotor3.reset(leftMotor3);
	m_rightMotor1.reset(rightMotor1);
	m_rightMotor2.reset(rightMotor2);
	m_rightMotor3.reset(rightMotor3);

	m_invertLeftSide = invertleftSide;
	m_invertRightSide = invertrightSide;

	m_safetyHelper = new MotorSafetyHelper(this);
	m_safetyHelper->SetSafetyEnabled(true);

	StopMotor();
}
