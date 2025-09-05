#include "chassis.hpp"
#include "chassis_monitor.hpp"
#include "motor_monitor.hpp"
#include "Pinpoint.hpp"

extern MotorController Motor_FR;
extern MotorController Motor_FL;
extern MotorController Motor_BR;
extern MotorController Motor_BL;
Chassis chassis(&Motor_FR, &Motor_FL , &Motor_BR, &Motor_BL);
float Vx_goal = 0.0;
float Vy_goal = 0.0;
float W_goal = 0.0;
float w_goal,x_goal,y_goal;
extern PinpointI2C::BulkData bd;
float x_error,y_error;


void chassis_monitor(void) {
	if(bd.pos_y_mm< y_goal){
		chassis.setSpeed(Vx_goal, 0.5, W_goal);
	}else{
		chassis.setSpeed(0,0,0);
	}
	chassis.getLocation();
}

