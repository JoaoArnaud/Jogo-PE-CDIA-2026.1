#ifndef JOGADOR_TECLADO_H
#define JOGADOR_TECLADO_H

#include "tabuleiro.h"
#include "jogador_remoto.h"

typedef struct {
    int tipo;
} JogadorTeclado;

void joga(JogadorTeclado jogador, Tabuleiro *tabuleiro, JogadorRemoto *remoto);

#endif