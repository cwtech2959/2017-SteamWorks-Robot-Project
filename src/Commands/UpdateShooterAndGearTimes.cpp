/*
 * UpdateShooterAndGearTimes.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: mriri
 */

#include <Commands/UpdateShooterAndGearTimes.h>
#include <SmartDashboard/SmartDashboard.h>

UpdateShooterAndGearTimes::UpdateShooterAndGearTimes() :
CommandBase("UpdateShooterAndGearTimes")
{
	Requires(ShooterSubsystem.get());
	Requires(GearManagementSubsystem.get());
}

UpdateShooterAndGearTimes::~UpdateShooterAndGearTimes() {
	// TODO Auto-generated destructor stub
}

void UpdateShooterAndGearTimes::Initialize()
{
	double gearGateTime = frc::SmartDashboard::GetNumber("Gear Gate Time", DefaultGearGateTime);
	GearManagementSubsystem->SetGearGateTime(gearGateTime);
	double startOffSetRightTime = frc::SmartDashboard::GetNumber("Start OffSet Right", StartOffSetRightTime);
	ShooterSubsystem->SetOffSetRight(startOffSetRightTime);
	double startOffSetLeft = frc::SmartDashboard::GetNumber("Start OffSet Left", StartOffSetLeftTime);
	ShooterSubsystem->SetOffSetLeft(startOffSetLeft);
	double onTime = frc::SmartDashboard::GetNumber("On Time", DefaultOnTime);
	ShooterSubsystem->SetOnTime(onTime);
	double offTime = frc::SmartDashboard::GetNumber("Off Time", DefaultOffTime);
	ShooterSubsystem->SetOffTime(offTime);
}

bool UpdateShooterAndGearTimes::IsFinished()
{
	return true;
}
