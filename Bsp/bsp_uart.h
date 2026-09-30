#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "main.h"
#include "usart.h"  

#define RX_BUFFER_SIZE 32

extern uint8_t rx_st[RX_BUFFER_SIZE];
extern DMA_HandleTypeDef hdma_usart1_rx;

void Bsp_Uart_Init(void);

#endif