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

constexpr int DefaultStartOffsetRightTime = 100;
constexpr int DefaultStartOffsetLeftTime = 100;
constexpr int DefaultOnTime = 10;
constexpr int DefaultOffTime = 10;

class Shooter : public Subsystem
{
	// private members
private:
	std::shared_ptr<Spark> BallFeederRight;
	std::shared_ptr<Spark> BallFeederLeft;

	int StartOffsetRight;
	int StartOffsetLeft;
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

	// Shooter feeder manipulation
	void StartBallFeeders();
	void StopBallFeeders();
	void ReverseBallFeeders();
	void BallFeederOff(ShooterSide side);
	void BallFeederOn(ShooterSide side);

	// member access

	// Shooter timing control
	void SetOffsetRight(int offsetTime);
	void SetOffsetLeft(int offsetTime);
	void SetOnTime(int time);
	void SetOffTime(int time);

	int GetOnTime();
	int GetOffTime();
	int GetOffsetTime(ShooterSide side);

	void SetShooting(bool state);
	bool GetShooting();

private:
	int LimitOffsetTime(int time);
	void SetBallFeedersSpeed(double speed);
	void SetBallFeedersSpeed(ShooterSide side, double speed);
};
#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
