/*
 * flame.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Admin
 */
#include "flame.h"

static struct _flame_device {
	GPIO_TypeDef *port;
	uint16_t pin;
} flame_device;

void flame_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN) {
	flame_device.port = GPIOx;
	flame_device.pin = GPIO_PIN;
}

uint8_t flame_get_data(void) {
	if (HAL_GPIO_ReadPin(flame_device.port, flame_device.pin) == 0)
		return 1;
	else
		return 0;
}

