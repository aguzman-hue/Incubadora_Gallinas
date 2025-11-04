/*
 * buzzer.c
 *
 *  Created on: Oct 27, 2025
 *      Author: PC
 */


#include "buzzer.h"
#include "stm32f3xx_hal.h"

#define BUZZER_PORT GPIOA
#define BUZZER_PIN  GPIO_PIN_8

void buzzer_init(void) {
  //configurado como GPIO_Output
}

void buzzer_on(void) {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
}

void buzzer_off(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); // callar buzzer
}
