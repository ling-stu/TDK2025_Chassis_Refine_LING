#include "chassis.hpp"
#include "chassis_monitor.hpp"
#include "motor_monitor.hpp"

extern MotorController Motor_FR;
extern MotorController Motor_FL;
extern MotorController Motor_BR;
extern MotorController Motor_BL;
int setspeed = 0;
Chassis chassis(&Motor_FR, &Motor_FL , &Motor_BR, &Motor_BL);
float Vx_goal = 0.0;
float Vy_goal = 0.0;
float W_goal = 0.0;


void chassis_monitor(void) {
	setspeed++;
//	chassis._motorFR->setSpeed(1);
    chassis.setSpeed(Vx_goal, Vy_goal, W_goal);
    chassis.getLocation();
}

