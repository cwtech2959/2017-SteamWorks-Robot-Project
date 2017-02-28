/*
 * FryingPanUpCommand.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: CW
 */

#include <Commands/MoveFryingPanCommand.h>
#include <Robot.h>
#include <Utilities.h>

MoveFryingPanCommand::MoveFryingPanCommand(bool up, int delayTime) :
		Command("FryingPanUpCommand")
{
	Requires(Robot::GearLoadSubsystem.get());
	Requires(Robot::GearManagementSubsystem.get());
	m_up = up;
	m_delayTime = delayTime;
}

MoveFryingPanCommand::~MoveFryingPanCommand()
{
}

void MoveFryingPanCommand::Initialize()
{
	SetTimeout(SecondsFromMilliSeconds(m_delayTime));
	if (m_up)
	{
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::DrivingUp);
	}
	else
	{
		Robot::GearManagementSubsystem->SetDrivingFryingPan(GearManagement::DrivingDown);
	}
}

void MoveFryingPanCommand::Execute()
{
	if (IsTimedOut())
	{
		Robot::GearManagementSubsystem->StartFryingPanMotor(m_up);
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
