#include <stdint.h>

#include "main.h"

#include "core.h"
#include "usb_debug.h"

bool core_init(void)
{
	usb_printf("core_init: done\r\n");

	return true;
}

void core_process(void)
{
	usb_printf("core_process\r\n");

	HAL_GPIO_TogglePin(uLED1_GPIO_Port, uLED1_Pin);

	HAL_Delay(1000);
}
