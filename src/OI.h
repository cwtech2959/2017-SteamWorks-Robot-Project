#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include "Buttons/JoystickButton.h"
#include <Triggers/ClearGearTrigger.h>

class OI
{
private:
	frc::JoystickButton FireButton { &DriverJoystick, 0 };
	frc::JoystickButton ReverseFireButton { &DriverJoystick, 3 };
	frc::JoystickButton ReverseLoadButton { &DriverJoystick, 1 };
	frc::JoystickButton PhotonCannonButton { &DriverJoystick, 4 };
	frc::JoystickButton GearDropOffButton { &DriverJoystick, 5 };
	frc::JoystickButton FryingPanUpButton { &DriverJoystick, 6 };
	frc::JoystickButton FryingPanDownButton { &DriverJoystick, 7 };
	ClearGearTrigger m_clearGearTrigger;

public:
	OI();

	frc::Joystick DriverJoystick { 0 };
};

#endif  // OI_H
