/*
 * modulesim.h
 *
 *  Created on: May 4, 2025
 *      Author: Admin
 */

#ifndef SIM_MODULE_H
#define SIM_MODULE_H

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdio.h>

// Cấu hình
#define SIM_MAX_RETRY        5
#define SIM_TX_TIMEOUT      1000
#define SIM_RX_TIMEOUT      1000
#define DEFAULT_PHONE_NUMBER  "0336091961"


// Hàm public
HAL_StatusTypeDef SIM_Check(UART_HandleTypeDef *huart);
HAL_StatusTypeDef SIM_MakeCall(UART_HandleTypeDef *huart);
#endif

