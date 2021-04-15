#include "led.h"

#define LEDS_NUMBER 8

struct led_timer {
	uint32_t channel;
	TIM_HandleTypeDef *handle;
}

static led_timer[LEDS_NUMBER];

void led_set(uint8_t led, uint16_t value)
{
	TIM_OC_InitTypeDef sConfigOC;

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = value;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

	__HAL_TIM_SET_COMPARE(led_timer[led].handle, led_timer[led].channel,
			      value);
}

bool led_init(uint8_t led, TIM_HandleTypeDef *htim, uint32_t channel)
{
	TIM_OC_InitTypeDef sConfigOC;

	led_timer[led].handle = htim;
	led_timer[led].channel = channel;

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

	HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, channel);

	HAL_TIM_PWM_Start(htim, channel);

	return true;
}
