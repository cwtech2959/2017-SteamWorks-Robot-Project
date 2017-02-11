/*
 * GearManagment.h
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_GEARMANAGEMENT_H_
#define SRC_SUBSYSTEMS_GEARMANAGEMENT_H_

#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include "RobotMap.h"
#include "Spark.h"

constexpr int DefaultGearGateTime = 500;

class GearManagement : public frc::Subsystem
{
private:
	frc::DigitalInput FryingPanUpSwitch
	{ FRYING_PAN_UP_DIO };
	frc::DigitalInput FryingPanDownSwitch
	{ FRYING_PAN_DOWN_DIO };
	frc::DigitalInput GearLoadReady
	{ GEAR_LOAD_READY_DIO };
	frc::DigitalInput GearOnFryingPan
	{ GEAR_ON_FRYING_PAN_DIO };

	frc::Spark FryingPanMotor
	{ FRYING_PAN_MOTOR_PWM };
	frc::Spark GearDropOffMotors
	{ GEAR_DROP_OFF_MOTORS_PWM };

	int GearGateTime;

public:
	GearManagement();
	virtual ~GearManagement();

	void StartGearDropOffMotors(bool open);
	void StopGearDropOffMotors();

	void SetGearGateTime(int time);
	int GetGearGateTime();
};

#endif /* SRC_SUBSYSTEMS_GEARMANAGEMENT_H_ */
