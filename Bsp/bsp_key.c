#include "bsp_key.h"

void Bsp_Key_Init(void)
{
}

uint8_t Bsp_Key_Read(void)
{
    return HAL_GPIO_ReadPin(key_GPIO_Port, key_Pin);
}