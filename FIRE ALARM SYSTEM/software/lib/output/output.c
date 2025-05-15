/*
 * output.c
 *
 *  Created on: May 7, 2025
 *      Author: Admin
 */
// output.c
#include "output.h"

/**
 * @brief  Bật đồng loạt các chân
 */
void Output_On(void) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) == GPIO_PIN_SET) {
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_3, GPIO_PIN_SET);
	}
}

/**
 * @brief  Tắt đồng loạt các chân
 */
void Output_Off(void) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) == GPIO_PIN_SET) {
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUTPUT_GPIO_PORT, OUTPUT_PIN_3, GPIO_PIN_RESET);
	}
}


