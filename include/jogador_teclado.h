#ifndef JOGADOR_TECLADO_H
#define JOGADOR_TECLADO_H

#include "tabuleiro.h"

typedef struct {
    int tipo;
} JogadorTeclado;

void joga(JogadorTeclado jogador, Tabuleiro *tabuleiro);

#endif