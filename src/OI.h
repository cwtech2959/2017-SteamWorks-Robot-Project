#ifndef OI_H
#define OI_H

#include <Joystick.h>

class OI {
public:
	OI();

	frc::Joystick DriverJoystick {0};
};

#endif  // OI_H
