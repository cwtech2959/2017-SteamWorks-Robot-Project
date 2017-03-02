#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <Triggers/ClearGearTrigger.h>
#include <Triggers/FryingPanUpTrigger.h>

class OI
{
private:
	std::shared_ptr<Joystick> DriverJoystick;
	std::shared_ptr<Joystick> ButtonBox;

	std::shared_ptr<JoystickButton> FireButton;
	std::shared_ptr<JoystickButton> ReverseFireButton;
	std::shared_ptr<JoystickButton> ReverseLoadButton;
	std::shared_ptr<JoystickButton> PhotonCannonButton;
	std::shared_ptr<JoystickButton> GearDropOffButton;
	std::shared_ptr<JoystickButton> FryingPanUpButton;
	std::shared_ptr<JoystickButton> FryingPanDownButton;
	std::shared_ptr<ClearGearTrigger> m_clearGearTrigger;
	std::shared_ptr<FryingPanUpTrigger> m_FryingPanUpTrigger;

public:
	OI();

	std::shared_ptr<Joystick> GetDriverJoystick();
};

#endif  // OI_H
