#include "keypad_logic.h"
#include "keypad.h"

static uint16_t tiempo_simulado = 0;
static uint16_t tiempo_confirmado = 0;
static bool entrada_completa = false;

void keypad_logic_init(void) {
  tiempo_simulado = 0;
  tiempo_confirmado = 0;
  entrada_completa = false;
}

void keypad_logic_update(void) {
  char tecla = keypad_read();
  if (tecla == 0 || entrada_completa) return;

  if (tecla >= '0' && tecla <= '9') {
    if (tiempo_simulado < 9999) {
      tiempo_simulado = tiempo_simulado * 10 + (tecla - '0');
    }
  } else if (tecla == '#') {
    tiempo_confirmado = tiempo_simulado * 60; // minutos → segundos
    entrada_completa = true;
  } else if (tecla == '*') {
    reset_entrada();
  } else if (tecla == 'A') {
    tiempo_confirmado = 20;
    entrada_completa = true;
  } else if (tecla == 'B') {
    tiempo_confirmado = 10;
    entrada_completa = true;
  } else if (tecla == 'C') {
    tiempo_confirmado = 5;
    entrada_completa = true;
  } else if (tecla == 'D') {
    tiempo_confirmado = 1;
    entrada_completa = true;
  }
}

bool entrada_finalizada(void) {
  return entrada_completa;
}

uint16_t get_tiempo_confirmado(void) {
  return tiempo_confirmado;
}

void reset_entrada(void) {
  tiempo_simulado = 0;
  tiempo_confirmado = 0;
  entrada_completa = false;
}
