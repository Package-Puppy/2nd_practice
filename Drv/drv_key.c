#include "drv_key.h"
#include "bsp_key.h"

static uint8_t  keysta = 0;
static uint16_t jiange = 0;
static KeyEvent_t event = KEY_NONE;

void Drv_Key_Scan(void)
{
    uint8_t cksta = Bsp_Key_Read();
    switch (keysta)
    {
    case 0:
        if (cksta == 0) { keysta = 1; jiange = 1; }
        break;
    case 1:
        if (cksta == 0)
        {
            jiange++;
            if (jiange >= 1000) { event = KEY_LONG_PRESS; keysta = 3; }
        }
        else
        {
            if (jiange < 300) { keysta = 2; jiange = 0; }
            else { keysta = 0; }
        }
        break;
    case 2:
        jiange++;
        if (cksta == 0) { event = KEY_DOUBLE_CLICK; keysta = 3; }
        else if (jiange > 300) { event = KEY_SHORT_PRESS; keysta = 0; }
        break;
    case 3:
        if (cksta == 1) { keysta = 0; }
        break;
    }
}

KeyEvent_t Drv_Key_GetEvent(void)
{
    KeyEvent_t e = event;
    event = KEY_NONE;
    return e;
}