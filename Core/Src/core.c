#include <stdint.h>

#include "main.h"

#include "core.h"
#include "led.h"
#include "usb_debug.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

static int pwm_value = 0;
static int step;

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

void core_process(void)
{

	usb_printf("core_process\r\n");

	HAL_GPIO_TogglePin(uLED1_GPIO_Port, uLED1_Pin);

	if (pwm_value == 0)
		step = 100;
	else if (pwm_value == 1000)
		step = -100;

	pwm_value += step;

	led_set(0, pwm_value);
	led_set(1, pwm_value);
	led_set(2, pwm_value);
	led_set(3, pwm_value);

	led_set(4, pwm_value);
	led_set(5, pwm_value);
	led_set(6, pwm_value);
	led_set(7, pwm_value);

	HAL_Delay(500);
}
