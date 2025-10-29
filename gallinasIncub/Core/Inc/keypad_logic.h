#ifndef KEYPAD_LOGIC_H
#define KEYPAD_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

void keypad_logic_init(void);
void keypad_logic_update(void);
bool entrada_finalizada(void);
uint16_t get_tiempo_confirmado(void);
void reset_entrada(void);

#endif
