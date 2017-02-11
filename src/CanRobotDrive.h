/*
 * CanRobotDrive.h
 *
 *  Created on: Feb 1, 2017
 *      Author: mriri
 */

#ifndef SRC_CANROBOTDRIVE_H_
#define SRC_CANROBOTDRIVE_H_

#include <memory>
#include <ErrorBase.h>
#include <MotorSafety.h>
#include <MotorSafetyHelper.h>
#include <CanTalonSRX.h>

class CanRobotDrive: public frc::ErrorBase, public frc::MotorSafety {
public:
	CanRobotDrive(CanTalonSRX * leftMotor1, CanTalonSRX * leftMotor2,
			CanTalonSRX * rightMotor1, CanTalonSRX * rightMotor2,
			bool invertLeftSide, bool invertRightSide);
	CanRobotDrive(CanTalonSRX * leftMotor1, CanTalonSRX * leftMotor2,
			CanTalonSRX * leftMotor3, CanTalonSRX * rightMotor1,
			CanTalonSRX * rightMotor2, CanTalonSRX * rightMotor3,
			bool invertLeftSide, bool invertRightSide);
	virtual ~CanRobotDrive();

	CanRobotDrive(const CanRobotDrive&) = delete;
	CanRobotDrive& operator=(const CanRobotDrive&) = delete;

	void TankDrive(double leftSide, double rightSide);

	void SetExpiration(double timeout) override;
	double GetExpiration() const override;
	bool IsAlive() const override;
	void StopMotor() override;
	bool IsSafetyEnabled() const override;
	void SetSafetyEnabled(bool enabled) override;
	void GetDescription(std::ostringstream& desc) const override;

private:
	int GetNumMotors();
	void InitRobotDrive(CanTalonSRX * leftMotor1, CanTalonSRX * leftMotor2,
			CanTalonSRX * leftMotor3, CanTalonSRX * rightMotor1,
			CanTalonSRX * rightMotor2, CanTalonSRX * rightMotor3,
			bool invertLeftSide, bool invertRightSide);
	double Limit(double num);

	static const int kMaxNumberOfMotors = 6;

	std::shared_ptr<CanTalonSRX> m_leftMotor1;
	std::shared_ptr<CanTalonSRX> m_leftMotor2;
	std::shared_ptr<CanTalonSRX> m_leftMotor3;
	std::shared_ptr<CanTalonSRX> m_rightMotor1;
	std::shared_ptr<CanTalonSRX> m_rightMotor2;
	std::shared_ptr<CanTalonSRX> m_rightMotor3;
	MotorSafetyHelper * m_safetyHelper;

	bool m_invertLeftSide;
	bool m_invertRightSide;
};

#endif /* SRC_CANROBOTDRIVE_H_ */
