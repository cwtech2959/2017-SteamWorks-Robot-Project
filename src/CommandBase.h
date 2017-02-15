#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/PhotonCannonSubsystem.h"
#include <Subsystems/GearManagement.h>
#include <Subsystems/Shooter.h>
#include <Subsystems/Loader.h>

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command
{
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<DriveTrain> DriveTrainSubsystem;
	static std::unique_ptr<Shooter> ShooterSubsystem;
	static std::unique_ptr<PhotonCannonSubsystem> myPhotonCannonSubsystem;
	static std::unique_ptr<GearManagement> GearManagementSubsystem;
	static std::unique_ptr<Loader> LoaderSubsystem;

};

#endif  // COMMAND_BASE_H
