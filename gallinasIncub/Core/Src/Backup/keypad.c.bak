/*
 * keypad.c
 *
 *  Created on: Oct 27, 2025
 *      Author: PC
 */
#include "keypad.h"
#include "stm32f3xx_hal.h"

// Define tus pines aquí si no usas pinmap.h
#define ROW_PORT GPIOA
uint16_t row_pins[4] = {GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4};

#define COL_PORT GPIOB
uint16_t col_pins[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};

// Mapa de teclas (puedes personalizarlo)
char keymap[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void keypad_init(void) {
  // Ya configurado en CubeMX como salidas (filas) y entradas con pull-up (columnas)
}

uint8_t keypad_read(void) {
  for (int row = 0; row < 4; row++) {
    // Activar una fila
    HAL_GPIO_WritePin(ROW_PORT, row_pins[row], GPIO_PIN_RESET);

    for (int col = 0; col < 4; col++) {
      if (HAL_GPIO_ReadPin(COL_PORT, col_pins[col]) == GPIO_PIN_RESET) {
        HAL_Delay(50); // Antirrebote
        HAL_GPIO_WritePin(ROW_PORT, row_pins[row], GPIO_PIN_SET);
        return keymap[row][col];
      }
    }

    // Desactivar la fila
    HAL_GPIO_WritePin(ROW_PORT, row_pins[row], GPIO_PIN_SET);
  }

  return 0; // Ninguna tecla presionada
}
