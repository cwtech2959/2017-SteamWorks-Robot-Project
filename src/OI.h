#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include "Buttons/JoystickButton.h"

class OI
{
public:
	OI();

	frc::Joystick DriverJoystick
	{ 0 };
	frc::JoystickButton FireButton
	{ &DriverJoystick, 0 };
	frc::JoystickButton LoadButton
	{ &DriverJoystick, 1 };
};

#endif  // OI_H
