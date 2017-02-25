#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// PWM channel mapping( Missing- Climb )
constexpr int BALL_PICKUP_PWM = 0;
constexpr int GEAR_DROP_OFF_MOTORS_PWM = 1;
constexpr int BALL_FEEDER_LEFT_PWM = 2;
constexpr int BALL_FEEDER_RIGHT_PWM = 3;
constexpr int CLIMB_PWM = 4;
constexpr int AIM_LIGHT_PWM = 5;
constexpr int FRYING_PAN_MOTOR_PWM = 6;

// DIO Mapping
constexpr int GEAR_LOAD_READY_DIO = 0;
constexpr int GEAR_ON_FRYING_PAN_DIO = 1;
constexpr int FRYING_PAN_DOWN_DIO = 2;
constexpr int FRYING_PAN_UP_DIO = 3;

// CAN Mapping( Missing- Drive and Ball Shooter's)

constexpr int LEFT_DRIVE_MOTOR_1_CAN = 1;
constexpr int LEFT_DRIVE_MOTOR_2_CAN = 2;
constexpr int GEAR_PICK_UP_ROLLER_CAN = 3;
constexpr int RIGHT_DRIVE_MOTOR_1_CAN = 4;
constexpr int RIGHT_DRIVE_MOTOR_2_CAN = 5;
constexpr int BALL_SHOOTER_RIGHT_CAN = 6;
constexpr int BALL_SHOOTER_LEFT_CAN = 7;


// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

#endif  // ROBOTMAP_H
