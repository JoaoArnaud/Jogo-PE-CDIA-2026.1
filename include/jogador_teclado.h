#ifndef JOGADOR_TECLADO_H
#define JOGADOR_TECLADO_H

#include "tabuleiro.h"
#include "jogador_remoto.h"

typedef struct {
    int tipo;
} JogadorTeclado;

// No modo online, "remoto" recebe a jogada via enviaJogada().
// No modo local, passe NULL: nada e enviado.
void joga(JogadorTeclado jogador, Tabuleiro *tabuleiro, JogadorRemoto *remoto);

#endif