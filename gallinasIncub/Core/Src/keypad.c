#include "keypad.h"

// Pines de filas (salidas)
#define ROW_PORT GPIOC
uint16_t row_pins[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};

// Pines de columnas (entradas con Pull-Up)
GPIO_TypeDef* col_ports[4] = {GPIOC, GPIOC, GPIOA, GPIOA};
uint16_t col_pins[4] = {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_11, GPIO_PIN_12};

// Mapa de teclas
char keymap[4][4] = {
  {'4', '5', '6', 'A'},
  {'1', '2', '3', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void keypad_init(void) {
  // Ya configurado en CubeMX: filas como salidas, columnas como entradas con Pull-Up
}

char keypad_read(void) {
  for (int row = 0; row < 4; row++) {
    // Desactivar todas las filas
    for (int r = 0; r < 4; r++) {
      HAL_GPIO_WritePin(ROW_PORT, row_pins[r], GPIO_PIN_SET);
    }

    // Activar fila actual
    HAL_GPIO_WritePin(ROW_PORT, row_pins[row], GPIO_PIN_RESET);

    for (int col = 0; col < 4; col++) {
      if (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_RESET) {
        HAL_Delay(50); // Antirrebote
        while (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_RESET); // Esperar liberación
        return keymap[row][col];
      }
    }
  }

  return 0; // Ninguna tecla presionada
}
