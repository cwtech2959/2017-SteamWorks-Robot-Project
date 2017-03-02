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

constexpr double DefaultGearGateTime = 1000;
constexpr double DefaultFryingPanUpDelayTime = 2000;
constexpr double DefaultGearReleaseDriveSpeed = 1;
constexpr double DefaultFryingPanDriveSpeed = 0.55;

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

	double GearGateTime;
	double FryingPanUpDelay;
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

	void SetGearGateTime(double time);
	double GetGearGateTime();

	void SetFryingPanUpDelayTime(double time);
	double GetFryingPanUpDelayTime();

	void SetFryingPanDriveSpeed(double speed);
	double GetFryingPanDriveSpeed();

	void SetGearReleaseDriveSpeed(double speed);
	double GetGearReleaseDriveSpeed();

	bool GetFryingPanUpSwitch();
	bool GetFryingPanDownSwitch();
	bool GetGearOnFryingPan();

	void SetDrivingFryingPan(DrivingFryingPan state);
	DrivingFryingPan GetDrvingFryingPan();

	void PrepareGearInit ();
};

#endif /* SRC_SUBSYSTEMS_GEARMANAGEMENT_H_ */
