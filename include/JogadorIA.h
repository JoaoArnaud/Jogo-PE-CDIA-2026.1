#ifndef JOGADOR_IA_H
#define JOGADOR_IA_H
 
#include "tabuleiro.h"
 
typedef struct {
    int tipo; // JOGADOR_X ou JOGADOR_O (mesmo padrão do JogadorTeclado)
} JogadorIA;
 
void jogaIA(JogadorIA jogador, Tabuleiro *tabuleiro);
 
#endif