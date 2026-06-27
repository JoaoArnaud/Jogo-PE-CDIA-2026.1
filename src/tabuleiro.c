#include <stdio.h>

typedef struct {
    int M[3][3];
} Tabuleiro;

enum {
    DESCONHECIDO = 0,
    JOGADOR_O = 1,
    EMPATE = 2,
    JOGADOR_X = 4
};

static Tabuleiro tabuleiro = {{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
}};

void desenha() {

    printf("\033[2J\033[H"); // limpa a tela

    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char simbolo = ' ';

            if (tabuleiro.M[i][j] == JOGADOR_X) {
                simbolo = 'X';
            } else if (tabuleiro.M[i][j] == JOGADOR_O) {
                simbolo = 'O';
            }

            printf(" %c ", simbolo);

            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");

        if (i < 2) {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}

int temVencedor() {
    int somas[8];
    int jogadas = 0;

    for (int i = 0; i < 3; i++) {
        somas[i] = tabuleiro.M[i][0] + tabuleiro.M[i][1] + tabuleiro.M[i][2];
        somas[i + 3] = tabuleiro.M[0][i] + tabuleiro.M[1][i] + tabuleiro.M[2][i];

        for (int j = 0; j < 3; j++) {
            if (tabuleiro.M[i][j] != DESCONHECIDO) {
                jogadas++;
            }
        }
    }

    somas[6] = tabuleiro.M[0][0] + tabuleiro.M[1][1] + tabuleiro.M[2][2];
    somas[7] = tabuleiro.M[0][2] + tabuleiro.M[1][1] + tabuleiro.M[2][0];

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

void marcaJogada(int x, int y, int tipo) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        if (tabuleiro.M[x][y] == DESCONHECIDO) {
            tabuleiro.M[x][y] = tipo;
            desenha();
        }
    }
}
