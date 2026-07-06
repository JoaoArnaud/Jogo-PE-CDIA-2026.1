#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogador_teclado.h"
#include "tabuleiro.h"

typedef struct {
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    Tabuleiro tabuleiro;
} Partida;

void configuraJogadores(Partida *partida);
void inicia(Partida *partida);

#endif
