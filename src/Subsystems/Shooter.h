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

constexpr double DefaultStartOffsetRightTime = 100;
constexpr double DefaultStartOffsetLeftTime = 100;
constexpr double DefaultOnTime = 10;
constexpr double DefaultOffTime = 10;

class Shooter : public Subsystem
{
	// private members
private:
	std::shared_ptr<Spark> BallFeederRight;
	std::shared_ptr<Spark> BallFeederLeft;

	double StartOffsetRight;
	double StartOffsetLeft;
	double OnTime;
	double OffTime;

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
	void SetOffsetRight(double offsetTime);
	void SetOffsetLeft(double offsetTime);
	void SetOnTime(double time);
	void SetOffTime(double time);

	double GetOnTime();
	double GetOffTime();
	double GetOffsetTime(ShooterSide side);

	void SetShooting(bool state);
	bool GetShooting();

private:
	double LimitOffsetTime(double time);
	void SetBallFeedersSpeed(double speed);
	void SetBallFeederSpeed(ShooterSide side, double speed);
};
#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
