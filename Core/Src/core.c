#include <stdint.h>

#include "main.h"

#include "adc.h"
#include "core.h"
#include "curve.h"
#include "dmx_receiver.h"
#include "encoder.h"
#include "led.h"
#include "usb_debug.h"

#define ADC_CHANNELS 		2

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

static uint16_t adc[ADC_CHANNELS];

static void process_adc(uint16_t *data)
{
	uint8_t ch;

	//HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

	for (ch = 0; ch < ADC_CHANNELS; ch++)
		adc[ch] = data[ch];
}

bool core_init(void)
{
	if (!adc_init(&hadc1, ADC_CHANNELS, process_adc))
		return false;

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
	unsigned int slots;
	unsigned int led;
	unsigned int channel;
	unsigned int now = HAL_GetTick();

	if (now - sec_tick > 1000) {
		sec_tick = now;
		HAL_GPIO_TogglePin(uLED1_GPIO_Port, uLED1_Pin);
	}

	/* Blocking receive packet */
	if ((slots = dmx_receive(packet)) == 0)
		return;

	/* Encoder can be set to value from 000 to 999 */
	channel = encoder_get();

	usb_dump(packet, slots, channel);

	/* limit slots by leds channels (first slot is type) */
	if (channel == 0 || channel > slots - LEDS_NUMBER)
		return;

	/* set first leds to first values from packet */
	for (led = 0; led < LEDS_NUMBER; led++)
		led_set(led, curve(packet[channel + led]));
}
