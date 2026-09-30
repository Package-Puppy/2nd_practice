#include "bsp_tim.h"
#include "tim.h"

void Bsp_Tim_Init(void)
{
    HAL_TIM_Base_Start_IT(&htim4);
}