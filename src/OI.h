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
	frc::JoystickButton ReverseFireButton
		{ &DriverJoystick, 3 };
	frc::JoystickButton ReverseLoadButton
		{ &DriverJoystick, 1 };
	frc::JoystickButton PhotonCannonButton
		{ &DriverJoystick, 4 };
	frc::JoystickButton GearDropOffButton
	    { &DriverJoystick, 5 };
};

#endif  // OI_H
