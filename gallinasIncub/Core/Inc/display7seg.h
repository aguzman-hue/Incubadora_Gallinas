#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

#include <stdint.h>

void display7seg_init(void);
void displayDigit(uint8_t digit);
void displayNumber(uint16_t number);  // Si querés mostrar más de un dígito


#endif
