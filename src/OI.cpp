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
#include <WPILib.h>
#include <Commands/ClearGearCommand.h>

OI::OI()
{
	// Process operator interface input here.
	FireButton.WhileHeld(new ParallelShootingCommandGroup());
	ReverseFireButton.WhileHeld(new ReverseFireCommand());
	ReverseLoadButton.WhileHeld(new ReverseLoaderCommand());
	PhotonCannonButton.WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton.WhenReleased(new PhotonCannonOffCommand());
	GearDropOffButton.WhenPressed(new GearDropOffCommand(true));
	GearDropOffButton.WhenReleased(new GearDropOffCommand(false));
	FryingPanUpButton.WhenPressed(new FryingPanUpCommand(true));
	FryingPanDownButton.WhenPressed(new FryingPanUpCommand(false));
	m_clearGearTrigger.WhenActive(new ClearGearCommand());

	frc::SmartDashboard::PutData("Update Shooter Speed", new UpdateShooterSpeed());
	frc::SmartDashboard::PutData("Update Shooter And Gear Times", new UpdateShooterAndGearTimes());
}
