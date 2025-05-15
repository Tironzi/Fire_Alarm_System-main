/*
 * mq-2.h
 *
 *  Created on: Apr 27, 2025
 *      Author: Admin
 */

#ifndef MQ_2_MQ_2_H_
#define MQ_2_MQ_2_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"


void mq2_Init(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);
uint8_t mq2_get_data(void);



#endif /* MQ_2_MQ_2_H_ */
