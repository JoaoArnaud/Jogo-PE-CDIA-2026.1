#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct {
    int M[3][3];
} Tabuleiro;

void desenha();
int temVencedor();

int marcaJogada(int x, int y, int tipo);

#endif
