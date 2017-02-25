/*
 * GearManagment.h
 *
 *  Created on: Feb 6, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_GEARMANAGEMENT_H_
#define SRC_SUBSYSTEMS_GEARMANAGEMENT_H_

#include <Commands/Subsystem.h>
#include "WPILib.h"

constexpr int DefaultGearGateTime = 500;
constexpr int DefaultFryingPanStallTime = 500;
constexpr int DefaultFryingPanUpDelayTime = 500;

class GearManagement : public Subsystem
{
private:
	std::shared_ptr<DigitalInput> FryingPanDownSwitch;
	std::shared_ptr<DigitalInput> FryingPanUpSwitch;
	std::shared_ptr<DigitalInput> GearOnFryingPan;

	std::shared_ptr<Spark> FryingPanMotor;
	std::shared_ptr<Spark> GearDropOffMotors;

	int GearGateTime;
	int FryingPanStallTime;
	int FryingPanUpDelay;

	enum DrivingFryingPan
	{
		Up, Down, DrivingUp, DrivingDown
	};

public:
	GearManagement();
	virtual ~GearManagement();

	void StartGearDropOffMotors(bool open);
	void StopGearDropOffMotors();

	void StartFryingPanMotor(bool up);
	void StopFryingPanMotor();

	void SetGearGateTime(int time);
		int GetGearGateTime();

	void SetFryingPanStallTime(int time);
	int GetFryingPanStallTime();

	bool GetFryingPanUpSwitch();
	bool GetFryingPanDownSwitch();
	bool GetGearOnFryingPan();
};

#endif /* SRC_SUBSYSTEMS_GEARMANAGEMENT_H_ */
