/*
 * display.h
 *
 *  Created on: May 6, 2025
 *      Author: Admin
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "stm32f1xx_hal.h"
#include "lcd.h"
#include "dht22.h"
#include "output.h"


void Display_Temp(float Temp);
void Display_Rh(float Rh);
void Display_Sim(int simcheck);
void Lcd_warning(float Temp, uint8_t *status, uint8_t *status_1);



#endif /* DISPLAY_H_ */
