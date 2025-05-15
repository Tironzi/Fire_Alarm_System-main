/*
 * mq-2.c
 *
 *  Created on: Apr 27, 2025
 *      Author: Admin
 */
#include "mq-2.h"

static struct _mq2_device {
	GPIO_TypeDef *port;
	uint16_t pin;
} mq2_device;

void mq2_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN) {
	mq2_device.port = GPIOx;
	mq2_device.pin = GPIO_PIN;
}

uint8_t mq2_get_data(void) {
	if (HAL_GPIO_ReadPin(mq2_device.port, mq2_device.pin) == 0)
		return 1;
	else
		return 0;
}


