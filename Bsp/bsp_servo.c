#include "bsp_servo.h"
#include "tim.h"

void Bsp_Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    __HAL_TIM_MOE_ENABLE(&htim1);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 1500);
}

void Bsp_Servo_SetPulse(uint16_t pulse)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, pulse);
}