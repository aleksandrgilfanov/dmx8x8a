/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_B1_Pin GPIO_PIN_0
#define ADC_B1_GPIO_Port GPIOC
#define ADC_A1_Pin GPIO_PIN_1
#define ADC_A1_GPIO_Port GPIOC
#define ADC_A2_Pin GPIO_PIN_2
#define ADC_A2_GPIO_Port GPIOC
#define ADC_B2_Pin GPIO_PIN_3
#define ADC_B2_GPIO_Port GPIOC
#define PWM_B1_Pin GPIO_PIN_1
#define PWM_B1_GPIO_Port GPIOA
#define PWM_A2_Pin GPIO_PIN_2
#define PWM_A2_GPIO_Port GPIOA
#define PWM_B2_Pin GPIO_PIN_3
#define PWM_B2_GPIO_Port GPIOA
#define ADC_B3_Pin GPIO_PIN_4
#define ADC_B3_GPIO_Port GPIOA
#define ADC_A3_Pin GPIO_PIN_5
#define ADC_A3_GPIO_Port GPIOA
#define PWM_A3_Pin GPIO_PIN_6
#define PWM_A3_GPIO_Port GPIOA
#define PWM_B3_Pin GPIO_PIN_7
#define PWM_B3_GPIO_Port GPIOA
#define ADC_B4_Pin GPIO_PIN_4
#define ADC_B4_GPIO_Port GPIOC
#define ADC_A4_Pin GPIO_PIN_5
#define ADC_A4_GPIO_Port GPIOC
#define PWM_B4_Pin GPIO_PIN_0
#define PWM_B4_GPIO_Port GPIOB
#define PWM_A4_Pin GPIO_PIN_1
#define PWM_A4_GPIO_Port GPIOB
#define uLED4_Pin GPIO_PIN_15
#define uLED4_GPIO_Port GPIOB
#define uLED3_Pin GPIO_PIN_6
#define uLED3_GPIO_Port GPIOC
#define uLED2_Pin GPIO_PIN_7
#define uLED2_GPIO_Port GPIOC
#define uLED1_Pin GPIO_PIN_8
#define uLED1_GPIO_Port GPIOC
#define Input11_S3_3_Pin GPIO_PIN_15
#define Input11_S3_3_GPIO_Port GPIOA
#define Input9_S3_1_Pin GPIO_PIN_10
#define Input9_S3_1_GPIO_Port GPIOC
#define Input10_S3_2_Pin GPIO_PIN_11
#define Input10_S3_2_GPIO_Port GPIOC
#define Input12_S3_4_Pin GPIO_PIN_12
#define Input12_S3_4_GPIO_Port GPIOC
#define Input5_S2_1_Pin GPIO_PIN_2
#define Input5_S2_1_GPIO_Port GPIOD
#define Input6_S2_2_Pin GPIO_PIN_3
#define Input6_S2_2_GPIO_Port GPIOB
#define Input8_S2_4_Pin GPIO_PIN_4
#define Input8_S2_4_GPIO_Port GPIOB
#define Input4_S1_4_Pin GPIO_PIN_5
#define Input4_S1_4_GPIO_Port GPIOB
#define Input7_S2_3_Pin GPIO_PIN_6
#define Input7_S2_3_GPIO_Port GPIOB
#define Input3_S1_3_Pin GPIO_PIN_7
#define Input3_S1_3_GPIO_Port GPIOB
#define Input2_S1_2_Pin GPIO_PIN_8
#define Input2_S1_2_GPIO_Port GPIOB
#define Input1_S1_1_Pin GPIO_PIN_9
#define Input1_S1_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
