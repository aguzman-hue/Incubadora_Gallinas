/*
 * lcd.h
 *
 *  Created on: Nov 10, 2025
 *      Author: PC
 */

#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>

// Inicializa el LCD en modo 4 bits
void lcd_init(void);

// Limpia la pantalla
void lcd_clear(void);

// Posiciona el cursor en fila y columna
void lcd_setCursor(uint8_t row, uint8_t col);

// Imprime una cadena de texto
void lcd_print(char *str);

// (Opcional) Imprime un entero como texto
void lcd_print_int(int val);

#endif
