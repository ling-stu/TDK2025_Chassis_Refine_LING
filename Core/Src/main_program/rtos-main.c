/*stm32 include*/
#include "stm32f446xx.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
//#include "motor_ctrl.hpp"
#include "timers.h"
#include "motor_monitor.hpp"
#include "trace.hpp"
#include "uros_init.h"
#include "motor_config.h"
#include "Pinpoint.hpp"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;
extern I2C_HandleTypeDef hi2c1;

uint16_t adcRead[7] = {0};

double LastCNT = 0;
double CNT = 500;
int turn =0;
double currentsp = 0;

//extern bool i2c_req;
//extern PinpointI2C pinpoint;
//PinpointI2C pinpoint(&hi2c1);
//PinpointI2C::BulkData bd;

TimerHandle_t xTimer;

void motorTimerCallback(TimerHandle_t xTimer);

void StartDefaultTask(void *argument)
{
    xTimer = xTimerCreate("MotorTimer", pdMS_TO_TICKS(100), pdTRUE, (void *)0, motorTimerCallback);
    xTimerStart(xTimer, 0);
//    HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
    motor_init();
//    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
//    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
//    pinpoint.Pinpoint_Init();
//    uros_init();
//    trace_init();

    for(;;)
    {
        uros_agent_status_check();
        osDelay(1000/FREQUENCY);
    }
}



void motorTimerCallback(TimerHandle_t xTimer)
{

//	motor_monitor();
//	i2c_req = 1;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, CNT);
//	pinpoint.taskloop();
//	CNT = __HAL_TIM_GET_COUNTER(&htim1);
//    turn = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1);
//    currentsp = ((CNT)/ ENCODER_RESOLUTION / REDUCTION_RATIO / 4) / (DT / 1000.0);
//    __HAL_TIM_SET_COUNTER(&htim1, 0);
}
//TODO:motor_PID,chassis,odometry,
//TODO: check other PWM output


