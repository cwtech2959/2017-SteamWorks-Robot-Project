#include "OI.h"

#include <WPILib.h>

#include "Commands/FireCommand.h"

OI::OI() {
	// Process operator interface input here.
	FireButton.WhenPressed(new FireCommand());

}
