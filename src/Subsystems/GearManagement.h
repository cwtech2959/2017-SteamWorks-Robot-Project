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
constexpr int DefaultFryingPanUpDelayTime = 500;
constexpr double DefaultGearReleaseDriveSpeed = 1;
constexpr double DefaultFryingPanDriveSpeed = 1;

class GearManagement : public Subsystem
{
public:
	enum DrivingFryingPan
	{
		Up,
		Down,
		DrivingUp,
		DrivingDown,
		Unknown
	};

private:
	std::shared_ptr<DigitalInput> FryingPanDownSwitch;
	std::shared_ptr<DigitalInput> FryingPanUpSwitch;
	std::shared_ptr<DigitalInput> GearOnFryingPan;

	std::shared_ptr<Spark> FryingPanMotor;
	std::shared_ptr<Spark> GearDropOffMotors;

	int GearGateTime;
	int FryingPanUpDelay;
	double FryingPanDriveSpeed;
	double GearReleaseDriveSpeed;

	DrivingFryingPan FryingPanState;

public:
	GearManagement();
	virtual ~GearManagement();

	void StartGearDropOffMotors(bool open);
	void StopGearDropOffMotors();

	void StartFryingPanMotor(bool up);
	void StopFryingPanMotor();

	void SetGearGateTime(int time);
	int GetGearGateTime();

	void SetFryingPanUpDelayTime(int time);
	int GetFryingPanUpDelayTime();

	void SetFryingPanDriveSpeed(double speed);
	double GetFryingPanDriveSpeed();

	void SetGearReleaseDriveSpeed(double speed);
	double GetGearReleaseDriveSpeed();

	bool GetFryingPanUpSwitch();
	bool GetFryingPanDownSwitch();
	bool GetGearOnFryingPan();

	void SetDrivingFryingPan(DrivingFryingPan state);
	DrivingFryingPan GetDrvingFryingPan();
};

#endif /* SRC_SUBSYSTEMS_GEARMANAGEMENT_H_ */
