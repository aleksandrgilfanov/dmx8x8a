#include "encoder.h"
#include "main.h"

static uint8_t rotary(uint8_t S)
{
	uint8_t In1, In2, In3, In4;

	switch (S) {
	case 1:
		In1 = HAL_GPIO_ReadPin(S1_1_GPIO_Port, S1_1_Pin);
		In2 = HAL_GPIO_ReadPin(S1_2_GPIO_Port, S1_2_Pin);
		In3 = HAL_GPIO_ReadPin(S1_3_GPIO_Port, S1_3_Pin);
		In4 = HAL_GPIO_ReadPin(S1_4_GPIO_Port, S1_4_Pin);
		break;
	case 2:
		In1 = HAL_GPIO_ReadPin(S2_1_GPIO_Port, S2_1_Pin);
		In2 = HAL_GPIO_ReadPin(S2_2_GPIO_Port, S2_2_Pin);
		In3 = HAL_GPIO_ReadPin(S2_3_GPIO_Port, S2_3_Pin);
		In4 = HAL_GPIO_ReadPin(S2_4_GPIO_Port, S2_4_Pin);
		break;
	case 3:
		In1 = HAL_GPIO_ReadPin(S3_1_GPIO_Port, S3_1_Pin);
		In2 = HAL_GPIO_ReadPin(S3_2_GPIO_Port, S3_2_Pin);
		In3 = HAL_GPIO_ReadPin(S3_3_GPIO_Port, S3_3_Pin);
		In4 = HAL_GPIO_ReadPin(S3_4_GPIO_Port, S3_4_Pin);
		break;
	default:
		return 0;
	}

	if (In1 == 0 && In2 == 0 && In3 == 0 && In4 == 0)
		return 0;
	if (In1 == 1 && In2 == 0 && In3 == 0 && In4 == 0)
		return 1;
	if (In1 == 0 && In2 == 0 && In3 == 1 && In4 == 0)
		return 2;
	if (In1 == 1 && In2 == 0 && In3 == 1 && In4 == 0)
		return 3;
	if (In1 == 0 && In2 == 1 && In3 == 0 && In4 == 0)
		return 4;
	if (In1 == 1 && In2 == 1 && In3 == 0 && In4 == 0)
		return 5;
	if (In1 == 0 && In2 == 1 && In3 == 1 && In4 == 0)
		return 6;
	if (In1 == 1 && In2 == 1 && In3 == 1 && In4 == 0)
		return 7;
	if (In1 == 0 && In2 == 0 && In3 == 0 && In4 == 1)
		return 8;
	if (In1 == 1 && In2 == 0 && In3 == 0 && In4 == 1)
		return 9;

	return 0;
}

uint16_t encoder_get(void)
{
	return 100 * rotary(3) + 10 * rotary(2) + rotary(1);
}
