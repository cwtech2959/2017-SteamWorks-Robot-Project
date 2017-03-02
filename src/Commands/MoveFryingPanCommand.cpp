/*
 * FryingPanUpCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/MoveFryingPanCommand.h>
#include <Robot.h>
#include <Utilities.h>

MoveFryingPanCommand::MoveFryingPanCommand(bool up) :
		Command("FryingPanUpCommand")
{
	Requires(Robot::GearLoadSubsystem.get());
	Requires(Robot::GearManagementSubsystem.get());
	m_up = up;
}

MoveFryingPanCommand::~MoveFryingPanCommand()
{
}

void MoveFryingPanCommand::Initialize()
{
	ramp.SetTargetSpeed(Robot::GearManagementSubsystem->GetFryingPanDriveSpeed() , 0);
	if (m_up)
	{
		SetTimeout(SecondsFromMilliSeconds(Robot::GearManagementSubsystem->GetFryingPanUpDelayTime()));
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::DrivingUp);
	}
	else
	{
		SetTimeout(0);
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::DrivingDown);
	}
}

void MoveFryingPanCommand::Execute()
{
	if (IsTimedOut())
	{
		Robot::GearManagementSubsystem->MoveFryingPan(m_up, ramp.NextSpeed());
	}
}

bool MoveFryingPanCommand::IsFinished()
{
	if (m_up && Robot::GearManagementSubsystem->GetFryingPanUpSwitch())
	{
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::Up);
		Robot::GearLoadSubsystem->Stop();
		return true;
	}
	else if (!m_up && Robot::GearManagementSubsystem->GetFryingPanDownSwitch())
	{
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::Down);
		Robot::GearLoadSubsystem->LoadGear();
		return true;
	}

	return false;
}

void MoveFryingPanCommand::End()
{
	Robot::GearManagementSubsystem->StopFryingPanMotor();
}

void MoveFryingPanCommand::Interrupted()
{
	Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::Unknown);
	End();
}
