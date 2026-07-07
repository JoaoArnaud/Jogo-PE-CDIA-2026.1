#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

#include "tabuleiro.h"

typedef struct {
    int tipo;          // JOGADOR_X ou JOGADOR_O
    int socket;        // Socket: comunicacao com o outro jogador
    int serverSocket;  // ServerSocket: socket de escuta (usado so pelo servidor)
} JogadorRemoto;

// accept(porta) do modelo: cria o ServerSocket e espera a conexao (servidor)
void aceita(JogadorRemoto *jogador, int porta);

// conecta(ip, porta): cria o Socket e conecta ao servidor (cliente)
void conecta(JogadorRemoto *jogador, const char *ip, int porta);

// Envia o numero da jogada (1-9) para o processo remoto
void enviaJogada(JogadorRemoto *jogador, int numero);

// joga() do JogadorRemoto: bloqueia esperando a jogada do processo remoto
// e a marca no tabuleiro
void jogaRemoto(JogadorRemoto *jogador, Tabuleiro *tabuleiro);

#endif
