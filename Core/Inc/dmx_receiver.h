#ifndef DMX_RECEIVER_H
#define DMX_RECEIVER_H

#include <stdint.h>

#define DMX_MAX_SLOTS 512

uint16_t dmx_receive(uint8_t* dest);
void dmx_uart_handler(UART_HandleTypeDef *huart);

#endif		/* DMX_RECEIVER_H */
