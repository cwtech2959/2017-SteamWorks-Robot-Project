#include "OI.h"
#include <Commands/PhotonCannonOffCommand.h>
#include <Commands/ReverseLoaderCommand.h>
#include <Commands/ParallelShootingCommandGroup.h>
#include <Commands/PhotonCannonOnCommand.h>
#include <Commands/ReverseFireCommand.h>
#include <Commands/GearDropOffCommand.h>
#include <Commands/FryingPanUpCommand.h>
#include <Commands/UpdateShooterAndGearTimes.h>
#include <Commands/UpdateShooterSpeed.h>
#include <Commands/ClearGearCommand.h>

OI::OI()
{
	DriverJoystick.reset(new Joystick(0));

	FireButton.reset(new JoystickButton(DriverJoystick.get(), 1));
	ReverseFireButton.reset(new JoystickButton(DriverJoystick.get(), 4));
	ReverseLoadButton.reset(new JoystickButton(DriverJoystick.get(), 2));
	PhotonCannonButton.reset(new JoystickButton(DriverJoystick.get(), 5));
	GearDropOffButton.reset(new JoystickButton(DriverJoystick.get(), 6));
	FryingPanUpButton.reset(new JoystickButton(DriverJoystick.get(), 7));
	FryingPanDownButton.reset(new JoystickButton(DriverJoystick.get(), 8));
	m_clearGearTrigger.reset(new ClearGearTrigger());

	// Process operator interface input here.
	FireButton->WhileHeld(new ParallelShootingCommandGroup());
	ReverseFireButton->WhileHeld(new ReverseFireCommand());
	ReverseLoadButton->WhileHeld(new ReverseLoaderCommand());
	PhotonCannonButton->WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton->WhenReleased(new PhotonCannonOffCommand());
	GearDropOffButton->WhenPressed(new GearDropOffCommand(true));
	GearDropOffButton->WhenReleased(new GearDropOffCommand(false));
	FryingPanUpButton->WhenPressed(new FryingPanUpCommand(true));
	FryingPanDownButton->WhenPressed(new FryingPanUpCommand(false));
	m_clearGearTrigger->WhenActive(new ClearGearCommand());

	SmartDashboard::PutData("Reverse Fire Command", new ReverseFireCommand());
	SmartDashboard::PutData("Reverse Loader Command", new ReverseLoaderCommand());
	SmartDashboard::PutData("Photon Cannon Off Command", new PhotonCannonOnCommand());
	SmartDashboard::PutData("Photon Cannon On Command", new PhotonCannonOffCommand());
	SmartDashboard::PutData("Gear Drop Off Command", new GearDropOffCommand(true));
	SmartDashboard::PutData("Frying Pan Up Command", new FryingPanUpCommand(true));

	SmartDashboard::PutData("Update Shooter Speed", new UpdateShooterSpeed());
	SmartDashboard::PutData("Update Shooter And Gear Times", new UpdateShooterAndGearTimes());
}

std::shared_ptr<Joystick> OI::GetDriverJoystick()
{
	return DriverJoystick;
}
