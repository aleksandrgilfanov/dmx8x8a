#include <stdint.h>

#include "main.h"

#include "core.h"
#include "curve.h"
#include "dmx_receiver.h"
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
static unsigned char packet[DMX_MAX_SLOTS + 1];

void core_process(void)
{
	int slots;
	int led;
	unsigned int now = HAL_GetTick();

	if (now - sec_tick > 1000) {
		sec_tick = now;
		HAL_GPIO_TogglePin(uLED1_GPIO_Port, uLED1_Pin);
	}

	/* Receive and dump packet */
	if ((slots = dmx_receive(packet)) > 0)
		usb_dumppacket(packet, slots);

	/* limit slots by leds channels (first byte is used for type) */
	if (slots > LEDS_NUMBER + 1)
		slots = LEDS_NUMBER + 1;

	/* set first leds to first values from packet */
	for (led = 0; led < slots - 1; led++)
		led_set(led, curve(packet[led + 1]));
}
