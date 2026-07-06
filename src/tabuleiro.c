#include <stdio.h>
#include "../include/tabuleiro.h"

void desenha(Tabuleiro *tabuleiro) {
    printf("\033[2J\033[H");
    printf("\n");

    for (int i = 0; i < 3; i++) {
        // Primeiro tabuleiro: com números
        for (int j = 0; j < 3; j++) {
            printf(" %d ", i * 3 + j + 1);
            if (j < 2) printf("|");
        }

        printf("          ");

        // Segundo tabuleiro: sem números
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] == JOGADOR_X) {
                printf(" X ");
            } else if (tabuleiro->M[i][j] == JOGADOR_O) {
                printf(" O ");
            } else {
                printf("   ");
            }

            if (j < 2) printf("|");
        }

        printf("\n");

        if (i < 2) {
            printf("---+---+---          ---+---+---\n");
        }
    }

    printf("\n");
}

EstadoJogo temVencedor(Tabuleiro *tabuleiro) { // saí do padrão estabelecido no documento do trabalho, mas entra no pedido pelo professor
    int somas[8];
    int jogadas = 0;

    for (int i = 0; i < 3; i++) {
        somas[i] = tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2];
        somas[i + 3] = tabuleiro->M[0][i] + tabuleiro->M[1][i] + tabuleiro->M[2][i];

        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] != DESCONHECIDO) {
                jogadas++;
            }
        }
    }

    somas[6] = tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2];
    somas[7] = tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0];

    for (int i = 0; i < 8; i++) {
        if (somas[i] == JOGADOR_O * 3) {
            return JOGADOR_O;
        }

        if (somas[i] == JOGADOR_X * 3) {
            return JOGADOR_X;
        }
    }

    if (jogadas == 9) {
        return EMPATE;
    }

    return DESCONHECIDO;
}

int marcaJogada(Tabuleiro *tabuleiro, int x, int y, EstadoJogo tipo) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        if (tabuleiro->M[x][y] == DESCONHECIDO) {
            tabuleiro->M[x][y] = tipo;
            desenha(tabuleiro);
            return 1;
        }
    }
    return 0;
}

int marcaJogadaPorNumero(Tabuleiro *tabuleiro, int numero, int tipo) {
    if (numero == 1) {
        return marcaJogada(tabuleiro, 0, 0, tipo);
    } else if (numero == 2) {
        return marcaJogada(tabuleiro, 0, 1, tipo);
    } else if (numero == 3) {
        return marcaJogada(tabuleiro, 0, 2, tipo);
    } else if (numero == 4) {
        return marcaJogada(tabuleiro, 1, 0, tipo);
    } else if (numero == 5) {
        return marcaJogada(tabuleiro, 1, 1, tipo);
    } else if (numero == 6) {
        return marcaJogada(tabuleiro, 1, 2, tipo);
    } else if (numero == 7) {
        return marcaJogada(tabuleiro, 2, 0, tipo);
    } else if (numero == 8) {
        return marcaJogada(tabuleiro, 2, 1, tipo);
    } else if (numero == 9) {
        return marcaJogada(tabuleiro, 2, 2, tipo);
    }

    return 0;
}
