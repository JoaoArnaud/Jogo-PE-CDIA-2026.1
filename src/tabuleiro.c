#include <stdio.h>
#include "../include/tabuleiro.h"
#include "../include/menu.h"

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

int marcaJogada(Tabuleiro *tabuleiro, int numero, EstadoJogo tipo) {
    int contador = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (contador == numero) {
                if (tabuleiro->M[i][j] == DESCONHECIDO) {
                    tabuleiro->M[i][j] = tipo;
                    desenha(tabuleiro);
                    return 1;
                } else {
                    return 0;
                }
            }
            
            contador++;
        }
    }

    return 0;
}

