#include <stdbool.h>
#include <string.h>

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"

#include "dmx_receiver.h"

/* Packet byte counter, used while receiving is still in process */
static uint16_t DMXChannelCount = 0;

/* DMX Packet buffer with one byte for first 0x00 */
uint8_t Packet[DMX_MAX_SLOTS + 1];
/* Received packet */
uint8_t ReceivedPacket[DMX_MAX_SLOTS + 1];
/* Flag that indicates succesfully received packet */
static uint8_t ReceivedFlag = 0;
/* Length of received packet */
static uint16_t ReceivedLength = 0;

/* Blocking receive entire DMX packet */
uint16_t dmx_receive(uint8_t* dest)
{
	uint16_t len;

	while (ReceivedFlag == 0) {};

	len = ReceivedLength;
	memcpy(dest, ReceivedPacket, len);

	ReceivedFlag = 0;

	return len;
}

/* Frame Error is detected by UART after 10bits of low level. So it is Break */
static void frame_error_handler()
{
	/* Do nothing if there is no packet in buffer */
	if (DMXChannelCount == 0)
		return;

	/* Save received packet */
	memcpy(ReceivedPacket, Packet, DMXChannelCount);
	ReceivedLength = DMXChannelCount;
	ReceivedFlag = 1;

	/* Prepare counter for receiving slots of next packet */
	DMXChannelCount = 0;
}

static void receive_data_handler(uint32_t Data)
{
	/* Drop packet if there is no free space in buffer */
	if (DMXChannelCount > (DMX_MAX_SLOTS + 1)) {
		DMXChannelCount = 0;
		return;
	}

	/* Cyclic write slot data into buffer */
	Packet[DMXChannelCount++] = Data;
}

void dmx_uart_handler(UART_HandleTypeDef *huart)
{
	uint32_t StatusRead = huart->Instance->SR;
	uint32_t Data = huart->Instance->DR;

	/* Frame Error interrupt happens after 10 bits of 0 (~40us), so it is
	 * after first 40 us of Break */
	if ((StatusRead & UART_FLAG_FE) == UART_FLAG_FE) {
		frame_error_handler();
		__HAL_UART_CLEAR_FEFLAG(huart);
		return;
	}

	/* Receive Data interrupt */
	if ((StatusRead & UART_FLAG_RXNE) == UART_FLAG_RXNE) {
		receive_data_handler(Data);
		__HAL_UART_CLEAR_FLAG(huart, UART_FLAG_RXNE);
	}
}
