#include "OI.h"
#include <Commands/PhotonCannonOffCommand.h>
#include <Commands/ReverseLoaderCommand.h>
#include <Commands/StartFireSequenceCommand.h>
#include <Commands/PhotonCannonOnCommand.h>
#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.
	FireButton.WhileHeld(new StartFireSequenceCommand());
	ReverseLoadButton.WhileHeld(new ReverseLoaderCommand());
	PhotonCannonButton.WhenPressed(new PhotonCannonOnCommand());
	PhotonCannonButton.WhenReleased(new PhotonCannonOffCommand());
}
