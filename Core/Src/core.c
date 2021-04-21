#include <stdint.h>

#include "main.h"

#include "core.h"
#include "curve.h"
#include "led.h"
#include "usb_debug.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

bool core_init(void)
{
	if (!led_init(0, &htim2, TIM_CHANNEL_1) ||
	    !led_init(1, &htim2, TIM_CHANNEL_2) ||
	    !led_init(2, &htim2, TIM_CHANNEL_3) ||
	    !led_init(3, &htim2, TIM_CHANNEL_4) ||
	    !led_init(4, &htim3, TIM_CHANNEL_1) ||
	    !led_init(5, &htim3, TIM_CHANNEL_2) ||
	    !led_init(6, &htim3, TIM_CHANNEL_4) ||
	    !led_init(7, &htim3, TIM_CHANNEL_3))
		return false;

	usb_printf("core_init: done\r\n");

	return true;
}

static unsigned int sec_tick = 0;

void core_process(void)
{
	unsigned int now = HAL_GetTick();

	if (now - sec_tick > 1000) {
		sec_tick = now;
		HAL_GPIO_TogglePin(uLED1_GPIO_Port, uLED1_Pin);
	}
}
