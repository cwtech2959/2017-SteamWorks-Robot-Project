#include <Commands/ToggleFireCommand.h>
#include <Commands/ToggleLoadCommand.h>
#include "OI.h"

#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.
	FireButton.WhenPressed(new ToggleFireCommand());
	LoadButton.WhenPressed(new ToggleLoadCommand());
}
