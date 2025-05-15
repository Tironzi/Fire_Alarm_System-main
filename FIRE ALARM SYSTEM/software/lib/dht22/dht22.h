/*
 * dht22.h
 *
 *  Created on: Apr 27, 2025
 *      Author: Admin
 */

#ifndef DHT22_H_
#define DHT22_H_

#include "stm32f1xx_hal.h"
#include "delay.h"

extern uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
extern uint16_t SUM, RH, TEMP;
extern float Temperature;
extern float Humidity;

// Định nghĩa các chân kết nối DHT22
#define DHT22_PORT GPIOB
#define DHT22_PIN GPIO_PIN_0

uint8_t DHT22_GetData(float *Temperature, float *Humidity);


#endif /* DHT22_H_ */

