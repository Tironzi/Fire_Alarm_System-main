/*
 * display.c
 *
 *  Created on: May 6, 2025
 *      Author: Admin
 */
#include "../warning/display.h"


Lcd_HandleTypeDef lcd;
extern UART_HandleTypeDef huart1;

void Display_Temp(float Temp) {
	char str[20] = { 0 };
	Lcd_cursor(&lcd, 0, 0);
	sprintf(str, "TEMP:- %.2f ", Temp);
	Lcd_string(&lcd, str);
	Lcd_string(&lcd, "C");
}

void Display_Rh(float Rh) {
		char str[20] = { 0 };
		Lcd_cursor(&lcd, 1, 0);
		sprintf(str, "RH:- %.2f ", Rh);
		Lcd_string(&lcd, str);
		Lcd_string(&lcd, "%");
}


void Display_Sim(int simcheck) {
		if (simcheck == HAL_OK) {
			Lcd_cursor(&lcd, 1, 14);
			Lcd_string(&lcd, "4G");
	} else {
			Lcd_string(&lcd, "NO_SIM");
	}
}
void Lcd_warning(float Temp, uint8_t *status, uint8_t *status_1) {

	if (Temp > 35 && *status == 0 && mq2_get_data() == 0
			&& flame_get_data() == 0) {
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0, 0);
		Lcd_string(&lcd, "OVER HEAT!!!");
		Output_On();
		SIM_MakeCall(&huart1);

			*status = 1;
		}

	else if (Temp <= 35 && *status == 1 && mq2_get_data() == 0
			&& flame_get_data() == 0) {
		Lcd_clear(&lcd);

		Output_Off();
			*status = 0;
		}
	if (mq2_get_data() == 1 && *status == 0 && Temp < 35
			&& flame_get_data() == 0) {
		Lcd_clear(&lcd);
		Lcd_cursor(&lcd, 0, 0);
		Lcd_string(&lcd, "Gas detect !!!");
		Output_On();
		SIM_MakeCall(&huart1);
		*status = 1;
	} else if (mq2_get_data() == 0 && *status == 1 && Temp < 35
			&& flame_get_data() == 0) {
		Lcd_clear(&lcd);
		Output_Off();
		*status = 0;
	}

	if (flame_get_data() == 1 && *status == 0 && Temp < 35
			&& mq2_get_data() == 0) {
		Lcd_clear(&lcd);
		Lcd_cursor(&lcd, 0, 0);
		Lcd_string(&lcd, "Fire detect !!!");
		Output_On();
		SIM_MakeCall(&huart1);
		*status = 1;
	} else if (flame_get_data() == 0 && *status == 1 && Temp < 35
			&& mq2_get_data() == 0) {
		Lcd_clear(&lcd);
		Output_Off();
		*status = 0;
	}
	if ((Temp > 35 && mq2_get_data() == 1)
			|| (Temp > 35 && flame_get_data() == 1)
			|| (mq2_get_data() == 1 && flame_get_data() == 1)) {
		if (*status_1 == 0) {
		Lcd_clear(&lcd);
		Lcd_cursor(&lcd, 0, 0);
		Lcd_string(&lcd, "FIRE WARNING !!!");
			Output_On();
			SIM_MakeCall(&huart1);
			*status_1 = 1;
		}
	} else if ((Temp < 35 && mq2_get_data() == 0)
			|| (Temp < 35 && flame_get_data() == 0)
			|| (mq2_get_data() == 0 && flame_get_data() == 0)) {
		if (*status_1 == 1) {
		Lcd_clear(&lcd);
		*status = 0;
		*status_1 = 0;
			Output_Off();
		}
	}
}



