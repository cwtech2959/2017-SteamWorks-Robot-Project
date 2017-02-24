/*
 * ShooterAndLoader.h
 *
 *  Created on: Jan 23, 2017
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <CanTalon.h>

constexpr int StartOffSetRightTime = 100;
constexpr int StartOffSetLeftTime = 100;
constexpr int DefaultOnTime = 10;
constexpr int DefaultOffTime = 10;
constexpr double DefaultShooterSpeed = 0.65;

class Shooter : public Subsystem
{
	// private members
private:
	std::shared_ptr<Spark> ShooterConveyorRight;
	std::shared_ptr<Spark> ShooterConveyorLeft;

	std::shared_ptr<CANTalon> BallShooterLeft;
	std::shared_ptr<CANTalon> BallShooterRight;

	int StartOffSetRight;
	int StartOffSetLeft;
	int OnTime;
	int OffTime;

	bool Shooting;

public:
	enum ShooterSide
	{
		leftShooter,
		rightShooter
	};

public:
	Shooter();
	virtual ~Shooter();

	void StopAllConveyors();

	void SetBallShootersSpeed(double speed);

	// Loader conveyor manipulation


	// Shooter feeder manipulation
	void StartShooterConveyors();
	void ShooterConveyorsOff();
	void ReverseShooterConveyors();
	void ShooterConveyorOff(ShooterSide side);
	void ShooterConveyorOn(ShooterSide side);

	// member access

	// Shooter timing control
	void SetOffSetRight(int offsetTime);
	void SetOffSetLeft(int offsetTime);
	void SetOnTime(int time);
	void SetOffTime(int time);

	int GetOnTime();
	int GetOffTime();
	int GetOffsetTime(ShooterSide side);

	void SetShooting(bool state);
	bool GetShooting();

private:
	int LimitOffsetTime(int time);
	void SetShooterConveyorsSpeed(double speed);
	void SetShooterConveyorSpeed(ShooterSide side, double speed);
};
#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
