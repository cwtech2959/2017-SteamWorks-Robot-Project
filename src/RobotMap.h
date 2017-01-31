#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// PWM channel mapping
constexpr int LEFT_MOTOR1_PWM = 0;
constexpr int LEFT_MOTOR2_PWM = 1;
constexpr int RIGHT_MOTOR1_PWM = 2;
constexpr int RIGHT_MOTOR2_PWM = 3;
constexpr int SHOOTER_CONVEYOR_RIGHT_PWM = 4;
constexpr int SHOOTER_CONVEYOR_LEFT_PWM = 5;
constexpr int LOADER_CONVEYOR_PWM = 6;
constexpr int PHOTON_CANNON_PWM = 7;


// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

#endif  // ROBOTMAP_H
