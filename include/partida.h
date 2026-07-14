#ifndef PARTIDA_H
#define PARTIDA_H
 
#include "jogador_teclado.h"
#include "JogadorIA.h"
#include "tabuleiro.h"
 
typedef enum {
    PARTIDA_DOIS_JOGADORES,
    PARTIDA_CONTRA_IA
} TipoPartida;
 
typedef struct {
    TipoPartida tipo;
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    JogadorIA jogadorIA;
    Tabuleiro tabuleiro;
} Partida;
 
void configuraJogadores(Partida *partida);
void configuraJogadorIA(Partida *partida);
void inicia(Partida *partida);
 
#endif