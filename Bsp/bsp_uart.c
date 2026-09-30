#include "bsp_uart.h"

uint8_t rx_st[RX_BUFFER_SIZE];

void Bsp_Uart_Init(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_st, RX_BUFFER_SIZE);
    __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
}