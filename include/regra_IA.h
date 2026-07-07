#ifndef REGRAS_IA_H
#define REGRAS_IA_H
 
#include "tabuleiro.h"
 
// Recebe o tabuleiro atual, o tipo da IA e o tipo do adversário.
// Deve retornar a posição (1-9) escolhida pela IA.
int decideJogada(Tabuleiro *tabuleiro, EstadoJogo tipoIA, EstadoJogo tipoAdversario);
 
#endif
 