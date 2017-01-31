#include <Commands/PhotonCannonOnCommand.h>
#include <Commands/ToggleFireCommand.h>
#include <Commands/ToggleLoadCommand.h>
#include "OI.h"
#include <Commands/PhotonCannonOffCommand.h>
#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.
	FireButton.WhenPressed(new ToggleFireCommand());
	LoadButton.WhenPressed(new ToggleLoadCommand());
	PhotonCannonButton.WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton.WhenReleased(new PhotonCannonOffCommand());
}
