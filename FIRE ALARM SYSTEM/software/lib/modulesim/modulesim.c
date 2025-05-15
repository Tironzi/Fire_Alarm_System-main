/*
 * modulesim.c
 *
 *  Created on: May 4, 2025
 *      Author: Admin
 */

#include "modulesim.h"

// Biến toàn cục
uint8_t simBuffer[100] = { 0 };

// Hàm khởi tạo SIM
HAL_StatusTypeDef SIM_Check(UART_HandleTypeDef *huart) {
	char ATcommand[80] = "AT\r\n";
	uint8_t ATisOK = 0;
	while (!ATisOK) {
		HAL_UART_Transmit(huart, (uint8_t*) ATcommand, strlen(ATcommand),
				SIM_TX_TIMEOUT);

		HAL_UART_Receive(huart, simBuffer, 100, SIM_RX_TIMEOUT);

		if (strstr((char*) simBuffer, "OK")) {
			memset(simBuffer, 0, sizeof(simBuffer));
			return HAL_OK;
			ATisOK = 1;
		}
		memset(simBuffer, 0, sizeof(simBuffer));
		HAL_Delay(1000);
	}
	return HAL_ERROR;
}

 // Hàm gọi điện (dùng số mặc định từ define)
HAL_StatusTypeDef SIM_MakeCall(UART_HandleTypeDef *huart) {
	// Sử dụng DEFAULT_PHONE_NUMBER đã define
	uint8_t ATisOK = 0;
	char ATcommand[80] = "ATD" DEFAULT_PHONE_NUMBER ";\r\n";
	while (!ATisOK) {
		HAL_UART_Transmit(huart, (uint8_t*) ATcommand, strlen(ATcommand),
			SIM_TX_TIMEOUT);
		HAL_UART_Receive(huart, simBuffer, 100, SIM_RX_TIMEOUT);
		if (strstr((char*) simBuffer, "OK")) {
		memset(simBuffer, 0, sizeof(simBuffer));
			ATisOK = 1;
		return HAL_OK;
	}
		memset(simBuffer, 0, sizeof(simBuffer));
		HAL_Delay(1000);
	}
	return HAL_ERROR;
}

