/*
 * delay.h
 *
 *  Created on: May 2, 2025
 *      Author: Admin
 */

#ifndef DELAY_H
#define DELAY_H

#include "stm32f1xx_hal.h"  // Thêm thư viện STM32 HAL

// Khai báo con trỏ tới timer handle
extern TIM_HandleTypeDef *delay_timer_handle;
extern TIM_HandleTypeDef *delay_timer_handle_ms;
// Hàm khởi tạo delay với timer handle
void Delay_Init(TIM_HandleTypeDef *timer_handle_us,
		TIM_HandleTypeDef *timer_handle_ms);

// Hàm delay cho thời gian microsecond
void delay_us(uint16_t us);
void delay_ms(uint16_t ms);
#endif // DELAY_H

