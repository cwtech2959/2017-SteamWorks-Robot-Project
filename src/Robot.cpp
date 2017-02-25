#include <Robot.h>
#include "WPILib.h"

std::unique_ptr<RopeClimb> Robot::ClimbSubsystem;
std::unique_ptr<DriveTrain> Robot::DriveTrainSubsystem;
std::unique_ptr<GearManagement> Robot::GearManagementSubsystem;
std::unique_ptr<Loader> Robot::LoaderSubsystem;
std::unique_ptr<PhotonCannon> Robot::PhotonCannonSubsystem;
std::unique_ptr<Shooter> Robot::ShooterSubsystem;
std::unique_ptr<ShooterMotors> Robot::ShooterMotorsSubsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit()
{
	// Init subsystems!
	ClimbSubsystem.reset(new RopeClimb());
	DriveTrainSubsystem.reset(new DriveTrain());
	GearManagementSubsystem.reset(new GearManagement());
	LoaderSubsystem.reset(new Loader());
	PhotonCannonSubsystem.reset(new PhotonCannon());
	ShooterSubsystem.reset(new Shooter());
	ShooterMotorsSubsystem.reset(new ShooterMotors());

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	SmartDashboard::PutData(ClimbSubsystem.get());
	SmartDashboard::PutData(DriveTrainSubsystem.get());
	SmartDashboard::PutData(GearManagementSubsystem.get());
	SmartDashboard::PutData(LoaderSubsystem.get());
	SmartDashboard::PutData(PhotonCannonSubsystem.get());
	SmartDashboard::PutData(ShooterSubsystem.get());
	SmartDashboard::PutData(ShooterMotorsSubsystem.get());
	// chooser.AddDefault("Default Auto", new ExampleCommand());
	// chooser.AddObject("My Auto", new MyAutoCommand());
	SmartDashboard::PutData("Auto Modes", &chooser);

	SmartDashboard::SetDefaultNumber("Shooter Speed", DefaultShooterSpeed);
	SmartDashboard::SetDefaultNumber("Gear Gate Time", DefaultGearGateTime);
	SmartDashboard::SetDefaultNumber("Frying Pan Stall Time", DefaultFryingPanStallTime);
	SmartDashboard::SetDefaultNumber("Start OffSet Right", StartOffSetRightTime);
	SmartDashboard::SetDefaultNumber("Start OffSet Left", StartOffSetLeftTime);
	SmartDashboard::SetDefaultNumber("On Time", DefaultOnTime);
	SmartDashboard::SetDefaultNumber("Off Time", DefaultOffTime);
	SmartDashboard::SetDefaultNumber("Gear Clear Time", DefaultClearTime);
	SmartDashboard::SetDefaultNumber("Frying Pan Up Delay Time", DefaultFryingPanUpDelayTime);
}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit()
{
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
	/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
	 if (autoSelected == "My Auto") {
	 autonomousCommand.reset(new MyAutoCommand());
	 }
	 else {
	 autonomousCommand.reset(new ExampleCommand());
	 } */

	autonomousCommand.reset(chooser.GetSelected());

	if (autonomousCommand.get() != nullptr)
	{
		autonomousCommand->Start();
	}

	double speed = SmartDashboard::GetNumber("Shooter Speed", DefaultShooterSpeed);
	ShooterMotorsSubsystem->SetBallShootersSpeed(speed);

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != nullptr)
	{
		autonomousCommand->Cancel();
	}

	double speed = SmartDashboard::GetNumber("Shooter Speed", DefaultShooterSpeed);
	ShooterMotorsSubsystem->SetBallShootersSpeed(speed);
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
