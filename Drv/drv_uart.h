#ifndef __DRV_UART_H
#define __DRV_UART_H

#include "main.h"

typedef enum {
    CMD_NONE = 0,
    CMD_SET_ON,
    CMD_SET_HZ,
    CMD_SET_RANK,
    CMD_SET_ANGLE,
    CMD_QUERY
} CmdType_t;

typedef struct {
    CmdType_t type;
    uint16_t  value;
} Cmd_t;

void Drv_Uart_Parse(uint16_t size);
Cmd_t Drv_Uart_GetCmd(void);
void Drv_Uart_SendStatus(uint8_t on, uint8_t hz, uint8_t rank);

#endif