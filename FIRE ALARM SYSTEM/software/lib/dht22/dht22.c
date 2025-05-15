/*
 * dht22.c
 *
 *  Created on: Apr 27, 2025
 *      Author: Admin
 */

#include "dht22.h"

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM, RH, TEMP;

float Temperature = 0;
float Humidity = 0;
uint8_t Presence = 0;

void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

uint8_t DHT22_Check_Response(void) {
	Set_Pin_Input(DHT22_PORT, DHT22_PIN);   // set as input
	uint8_t Response = 0;
	delay_us(40);  // wait for 40us
	if (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN))) // if the pin is low
	{
		delay_us(80);   // wait for 80us

		if ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
			Response = 1;  // if the pin is high, response is ok
		else
			Response = -1;
	}

	while ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
		;   // wait for the pin to go low
	return Response;
}

uint8_t DHT22_Read(void) {
	uint8_t i, j;
	for (j = 0; j < 8; j++) {
		while (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
			;   // wait for the pin to go high
		delay_us(40);   // wait for 40 us

		if (!(HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))   // if the pin is low
		{
			i &= ~(1 << (7 - j));   // write 0
		} else
			i |= (1 << (7 - j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin(DHT22_PORT, DHT22_PIN)))
			;  // wait for the pin to go low
	}
	return i;
 }
 uint8_t DHT22_GetData(float *Temperature, float *Humidity) {
 uint8_t Response = 0;
 // Start the DHT22 communication
 Set_Pin_Output(DHT22_PORT, DHT22_PIN); // set the pin as output
 HAL_GPIO_WritePin(DHT22_PORT, DHT22_PIN, 0);   // pull the pin low
	delay_us(1200);   // wait for > 1ms

 HAL_GPIO_WritePin(DHT22_PORT, DHT22_PIN, 1);   // pull the pin high
	delay_us(20);   // wait for 20us

 Set_Pin_Input(DHT22_PORT, DHT22_PIN);   // set as input

 // Check response from DHT22
 DHT22_Check_Response();
 Rh_byte1 = DHT22_Read();  // Read RH data
 Rh_byte2 = DHT22_Read();
 Temp_byte1 = DHT22_Read();  // Read Temperature data
 Temp_byte2 = DHT22_Read();
 SUM = DHT22_Read();  // Read checksum

 // Combine bytes to get RH and Temp
 TEMP = ((Temp_byte1 << 8) | Temp_byte2);
 RH = ((Rh_byte1 << 8) | Rh_byte2);

 // Convert to floating-point
 *Temperature = (float) (TEMP / 10.0);
 *Humidity = (float) (RH / 10.0);

 return Response; // Return the response, 1 means successful, -1 means failed
}




