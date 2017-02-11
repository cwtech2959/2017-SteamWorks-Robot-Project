#include "OI.h"
#include <Commands/PhotonCannonOffCommand.h>
#include <Commands/ReverseLoaderCommand.h>
#include <Commands/ParallelShootingCommandGroup.h>
#include <Commands/PhotonCannonOnCommand.h>
#include <Commands/ReverseFireCommand.h>
#include <Commands/GearDropOffCommand.h>
#include <Commands/UpdateShooterAndGearTimes.h>
#include <Commands/UpdateShooterSpeed.h>
#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.
	FireButton.WhileHeld(new ParallelShootingCommandGroup());
	ReverseFireButton.WhileHeld(new ReverseFireCommand());
	ReverseLoadButton.WhileHeld(new ReverseLoaderCommand());
	PhotonCannonButton.WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton.WhenReleased(new PhotonCannonOffCommand());
	GearDropOffButton.WhileHeld(new GearDropOffCommand());

	frc::SmartDashboard::PutData("Update Shooter Speed", new UpdateShooterSpeed());
	frc::SmartDashboard::PutData("Update Shooter And Gear Times", new UpdateShooterAndGearTimes());
}
