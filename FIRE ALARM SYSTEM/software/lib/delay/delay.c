/*
 * delay.c
 *
 *  Created on: May 2, 2025
 *      Author: Admin
 */
#include "delay.h"

TIM_HandleTypeDef *delay_timer_handle_us; // Pointer to timer handle for microsecond delay
TIM_HandleTypeDef *delay_timer_handle_ms; // Pointer to timer handle for millisecond delay

// Khởi tạo hàm delay với timer cụ thể cho microsecond và millisecond
void Delay_Init(TIM_HandleTypeDef *timer_handle_us,
		TIM_HandleTypeDef *timer_handle_ms) {
	delay_timer_handle_us = timer_handle_us;    // Timer cho micro giây
	delay_timer_handle_ms = timer_handle_ms;    // Timer cho mili giây

	HAL_TIM_Base_Start(delay_timer_handle_us);  // Bắt đầu timer cho micro giây
	HAL_TIM_Base_Start(delay_timer_handle_ms);  // Bắt đầu timer cho mili giây
}

// Hàm delay với thời gian microsecond
void delay_us(uint16_t us) {
	// Set counter của timer về 0
	__HAL_TIM_SET_COUNTER(delay_timer_handle_us, 0);

	// Chờ cho đến khi timer đếm đủ thời gian yêu cầu (micro giây)
	while (__HAL_TIM_GET_COUNTER(delay_timer_handle_us) < us)
		;
}

// Hàm delay với thời gian millisecond
void delay_ms(uint16_t ms) {

	__HAL_TIM_SET_COUNTER(delay_timer_handle_ms, 0);

	while (__HAL_TIM_GET_COUNTER(delay_timer_handle_ms) < 10 * ms)
		// lưu ý chỗ này nhé
		;
}
