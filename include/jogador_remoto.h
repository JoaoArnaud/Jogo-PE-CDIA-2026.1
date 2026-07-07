#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

#include "tabuleiro.h"

typedef struct {
    int tipo;
    int socket;
    int serverSocket;
} JogadorRemoto;

void aceita(JogadorRemoto *jogador, int porta);
void conecta(JogadorRemoto *jogador, const char *ip, int porta);
void enviaJogada(JogadorRemoto *jogador, int numero);
void jogaRemoto(JogadorRemoto *jogador, Tabuleiro *tabuleiro);

#endif
