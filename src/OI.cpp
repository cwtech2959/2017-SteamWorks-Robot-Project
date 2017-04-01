#include "OI.h"
#include <Commands/PhotonCannonOffCommand.h>
#include <Commands/ReverseLoaderCommand.h>
#include <Commands/ParallelShootingCommandGroup.h>
#include <Commands/PhotonCannonOnCommand.h>
#include <Commands/ReverseFireCommand.h>
#include <Commands/GearDropOffCommand.h>
#include <Commands/UpdateShooterAndGearTimes.h>
#include <Commands/UpdateShooterSpeed.h>
#include <Commands/ClearGearCommand.h>
#include <Commands/MoveFryingPanCommand.h>
#include <Commands/InvertTankCommand.h>
#include <Commands/DriveStraightCommand.h>
#include <Commands/PowerReduceCommand.h>
#include <Subsystems/GearManagement.h>
#include <Robot.h>

OI::OI()
{
	DriverJoystick.reset(new Joystick(0));
	ButtonBox.reset(new Joystick(1));
	ClimbJoystick.reset(new Joystick(2));

	PhotonCannonButton.reset(new JoystickButton(DriverJoystick.get(), 4));
	InvertTankDirectionButton.reset(new JoystickButton(DriverJoystick.get(), 5));
	DriveStraightButton.reset(new JoystickButton(DriverJoystick.get(), 6));
	PowerReduceButton.reset(new JoystickButton(DriverJoystick.get(), 7));

	ReverseLoadButton.reset(new JoystickButton(ButtonBox.get(), 1));
	ReverseFireButton.reset(new JoystickButton(ButtonBox.get(), 2));
	//ClimbButton.reset(new JoystickButton(ButtonBox.get(), 3));
	FireButton.reset(new JoystickButton(ButtonBox.get(), 4));
	GearDropOffButton.reset(new JoystickButton(ButtonBox.get(), 5));
	FryingPanUpButton.reset(new JoystickButton(ButtonBox.get(), 6));
	FryingPanDownButton.reset(new JoystickButton(ButtonBox.get(), 7));

	m_clearGearTrigger.reset(new ClearGearTrigger());
	m_FryingPanUpTrigger.reset(new FryingPanUpTrigger());

	// Process operator interface input here.
	FireButton->WhileHeld(new ParallelShootingCommandGroup());
	ReverseFireButton->WhileHeld(new ReverseFireCommand());
	ReverseLoadButton->WhileHeld(new ReverseLoaderCommand());
	PhotonCannonButton->WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton->WhenReleased(new PhotonCannonOffCommand());
	GearDropOffButton->WhenPressed(new GearDropOffCommand(true));
	GearDropOffButton->WhenReleased(new GearDropOffCommand(false));
	FryingPanUpButton->WhenPressed(new MoveFryingPanCommand(true));
	FryingPanDownButton->WhenPressed(new MoveFryingPanCommand(false));
	InvertTankDirectionButton->WhileHeld(new InvertTankCommand());
	DriveStraightButton->WhileHeld(new DriveStraightCommand());
	PowerReduceButton->WhileHeld(new PowerReduceCommand());
	m_clearGearTrigger->WhenActive(new ClearGearCommand());
	m_FryingPanUpTrigger->WhenActive(new MoveFryingPanCommand(true));

	SmartDashboard::PutData("Reverse Fire Command", new ReverseFireCommand());
	SmartDashboard::PutData("Reverse Loader Command", new ReverseLoaderCommand());
	SmartDashboard::PutData("Photon Cannon Off Command", new PhotonCannonOnCommand());
	SmartDashboard::PutData("Photon Cannon On Command", new PhotonCannonOffCommand());
	SmartDashboard::PutData("Gear Drop Off Open Command", new GearDropOffCommand(true));
	SmartDashboard::PutData("Gear Drop Off Close Command", new GearDropOffCommand(false));
	SmartDashboard::PutData("Frying Pan Up Command", new MoveFryingPanCommand(true));
	SmartDashboard::PutData("Frying Pan Down Command", new MoveFryingPanCommand(false));
	SmartDashboard::PutData("Clear Gear Command", new ClearGearCommand());
	SmartDashboard::PutData("Invert Tank Command", new InvertTankCommand());
	SmartDashboard::PutData("Drive Straight Command", new DriveStraightCommand());
	SmartDashboard::PutData("Power Reduce Command", new PowerReduceCommand());

	SmartDashboard::PutData("Update Shooter Speed", new UpdateShooterSpeed());
	SmartDashboard::PutData("Update Shooter And Gear Times", new UpdateShooterAndGearTimes());
}

std::shared_ptr<Joystick> OI::GetDriverJoystick()
{
	return DriverJoystick;
}

std::shared_ptr<Joystick> OI::GetClimbJoystick()
{
	return ClimbJoystick;
}
