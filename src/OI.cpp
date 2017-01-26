#include "OI.h"

#include <WPILib.h>

#include "Commands/FireCommand.h"
#include "Commands/LoadCommand.h"

OI::OI()
{
	// Process operator interface input here.
	FireButton.WhenPressed(new FireCommand());
	LoadButton.WhenPressed(new LoadCommand());
}
