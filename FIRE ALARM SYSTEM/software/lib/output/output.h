/*
 * output.h
 *
 *  Created on: May 7, 2025
 *      Author: Admin
 */

// output.h
#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "stm32f1xx_hal.h"

// ==== Cấu hình chân GPIO ====
// Chỉ cần sửa lại các dòng bên dưới để thay đổi cổng/chân
#define OUTPUT_GPIO_PORT    GPIOA
#define OUTPUT_PIN_1        GPIO_PIN_4 //PUMP
#define OUTPUT_PIN_2        GPIO_PIN_5 //LIGHT
#define OUTPUT_PIN_3        GPIO_PIN_6 //BUZZER
// =============================

// Khai báo hàm
void Output_On(void);
void Output_Off(void);

#endif /* OUTPUT_H_ */
