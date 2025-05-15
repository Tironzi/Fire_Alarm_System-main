/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "delay.h"
#include "dht22.h"
#include "flame.h"
#include "mq-2.h"
#include "lcd.h"
#include "modulesim.h"
#include "output.h"
#include "display.h"
#include "stdio.h"
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PUMP_OUT_Pin GPIO_PIN_4
#define PUMP_OUT_GPIO_Port GPIOA
#define LIGHT_OUT_Pin GPIO_PIN_5
#define LIGHT_OUT_GPIO_Port GPIOA
#define BUZZER_OUT_Pin GPIO_PIN_6
#define BUZZER_OUT_GPIO_Port GPIOA
#define DHT22_OUT_Pin GPIO_PIN_0
#define DHT22_OUT_GPIO_Port GPIOB
#define FLAME_IN_Pin GPIO_PIN_1
#define FLAME_IN_GPIO_Port GPIOB
#define MQ_2_Pin GPIO_PIN_2
#define MQ_2_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_13
#define RS_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_15
#define EN_GPIO_Port GPIOB
#define D4_OUT_Pin GPIO_PIN_6
#define D4_OUT_GPIO_Port GPIOC
#define D5_OUT_Pin GPIO_PIN_7
#define D5_OUT_GPIO_Port GPIOC
#define D6_OUT_Pin GPIO_PIN_8
#define D6_OUT_GPIO_Port GPIOC
#define D7_OUT_Pin GPIO_PIN_9
#define D7_OUT_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
