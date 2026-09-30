#include "bsp_led.h"

void Bsp_Led_Init(void)
{
    HAL_GPIO_WritePin(light_GPIO_Port, light_Pin, GPIO_PIN_SET);
}

void Bsp_Led_Toggle(void)
{
    HAL_GPIO_TogglePin(light_GPIO_Port, light_Pin);
}

void Bsp_Led_On(void)
{
    HAL_GPIO_WritePin(light_GPIO_Port, light_Pin, GPIO_PIN_RESET);
}

void Bsp_Led_Off(void)
{
    HAL_GPIO_WritePin(light_GPIO_Port, light_Pin, GPIO_PIN_SET);
}