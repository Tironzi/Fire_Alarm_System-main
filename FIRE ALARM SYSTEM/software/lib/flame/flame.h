/*
 * flame.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Admin
 */

#ifndef FLAME_H_
#define FLAME_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"


void flame_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);
uint8_t flame_get_data(void);


#endif /* FLAME_H_ */
;
