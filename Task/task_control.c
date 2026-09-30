#include "task_control.h"
#include "bsp_led.h"
#include "bsp_servo.h"
#include "drv_key.h"
#include "drv_uart.h"

static uint16_t count = 0;
static uint8_t  zt = 0;
static uint8_t  on = 1;
static uint8_t  hz = 1;
static uint8_t  rank = 0;
static uint16_t loc = 1500;

void Task_Control_Init(void)
{
    Bsp_Led_Init();
    Bsp_Servo_Init();
}

void Task_Control_Loop(void)
{
    Drv_Key_Scan();
    KeyEvent_t ev = Drv_Key_GetEvent();
    if (ev == KEY_SHORT_PRESS) { hz++; if (hz > 3) hz = 1; }
    else if (ev == KEY_DOUBLE_CLICK) { rank++; if (rank > 2) rank = 0; }
    else if (ev == KEY_LONG_PRESS) { on = !on; }

    Cmd_t c = Drv_Uart_GetCmd();
    if (c.type == CMD_SET_ON)    { on = c.value; }
    else if (c.type == CMD_SET_HZ)   { hz = c.value; if (hz > 3 || hz < 1) hz = 1; }
    else if (c.type == CMD_SET_RANK) { rank = c.value; if (rank > 2) rank = 0; }
    else if (c.type == CMD_SET_ANGLE) { Bsp_Servo_SetPulse(c.value); }
    else if (c.type == CMD_QUERY) { Drv_Uart_SendStatus(on, hz, rank); }

    if (on == 1)
    {
        count++;
        if (count >= 500 / hz)
        {
            count = 0;
            Bsp_Led_Toggle();
            if (zt == 0) { loc = 2500 - rank * 300; zt = 1; }
            else { loc = 500 + rank * 300; zt = 0; }
            Bsp_Servo_SetPulse(loc);
        }
    }
}