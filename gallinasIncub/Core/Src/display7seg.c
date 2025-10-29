#include "display7seg.h"
#include "stm32f3xx_hal.h"

void display7seg_init(void) {
  // Ya configurado como GPIO_Output en CubeMX
}

void displayDigit(uint8_t digit) {
  const uint8_t segmentMap[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
  };

  uint8_t segments = segmentMap[digit];
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (segments >> 0) & 1); // A
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (segments >> 1) & 1); // B
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (segments >> 2) & 1); // C
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (segments >> 3) & 1); // D
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (segments >> 4) & 1); // E
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (segments >> 5) & 1); // F
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (segments >> 6) & 1); // G
}

void displayNumber(uint16_t number) {
  uint8_t digits[4] = {
    (number / 1000) % 10,
    (number / 100) % 10,
    (number / 10) % 10,
    number % 10
  };

  GPIO_TypeDef* digitPorts[4] = {GPIOA, GPIOA, GPIOA, GPIOB};
  uint16_t digitPins[4] = {GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_8};

  for (int i = 0; i < 4; i++) {
    // Apagar todos los dígitos
    for (int j = 0; j < 4; j++) {
      HAL_GPIO_WritePin(digitPorts[j], digitPins[j], GPIO_PIN_RESET);
    }

    // Mostrar el dígito actual
    displayDigit(digits[i]);

    // Activar el dígito correspondiente
    HAL_GPIO_WritePin(digitPorts[i], digitPins[i], GPIO_PIN_SET);

    HAL_Delay(2); // Persistencia visual
  }
}
