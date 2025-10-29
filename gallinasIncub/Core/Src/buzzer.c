/*
 * buzzer.c
 *
 *  Created on: Oct 27, 2025
 *      Author: PC
 */


#include "buzzer.h"
#include "stm32f3xx_hal.h"

#define BUZZER_PORT GPIOA
#define BUZZER_PIN  GPIO_PIN_9

void buzzer_init(void) {
  // Ya configurado como GPIO_Output en CubeMX
}

void buzzer_on(void) {
  HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
}

void buzzer_off(void) {
  HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}
