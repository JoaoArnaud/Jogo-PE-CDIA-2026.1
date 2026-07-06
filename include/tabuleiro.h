#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef enum {
    DESCONHECIDO = 0,
    JOGADOR_O = 1,
    EMPATE = 2,
    JOGADOR_X = 4
} EstadoJogo;

typedef struct {
    int M[3][3];
} Tabuleiro;

void desenha(Tabuleiro *tabuleiro);
EstadoJogo temVencedor(Tabuleiro *tabuleiro);

int marcaJogada(Tabuleiro *tabuleiro, int x, int y, EstadoJogo tipo);

#endif
