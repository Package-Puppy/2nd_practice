#include "drv_uart.h"
#include "bsp_uart.h"
#include "usart.h"

static Cmd_t cmd = {CMD_NONE, 0};

void Drv_Uart_Parse(uint16_t size)
{
    if (size >= 4 && rx_st[0] == 0xAA && rx_st[size-1] == 0x55)
    {
        cmd.type = (CmdType_t)rx_st[1];
        cmd.value = rx_st[2];
        if (cmd.type == CMD_SET_ANGLE && size >= 5)
        {
            cmd.value = (rx_st[2] << 8) | rx_st[3];
        }
    }
}

Cmd_t Drv_Uart_GetCmd(void)
{
    Cmd_t c = cmd;
    cmd.type = CMD_NONE;
    return c;
}

void Drv_Uart_SendStatus(uint8_t on, uint8_t hz, uint8_t rank)
{
    uint8_t tx[] = {0xAA, on, hz, rank, 0x55};
    HAL_UART_Transmit_DMA(&huart1, tx, 5);
}