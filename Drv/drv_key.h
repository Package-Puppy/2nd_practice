#ifndef __DRV_KEY_H
#define __DRV_KEY_H

#include "main.h"

// 按键事件枚举
typedef enum {
    KEY_NONE = 0,
    KEY_SHORT_PRESS,
    KEY_DOUBLE_CLICK,
    KEY_LONG_PRESS
} KeyEvent_t;

void Drv_Key_Scan(void);
KeyEvent_t Drv_Key_GetEvent(void);

#endif