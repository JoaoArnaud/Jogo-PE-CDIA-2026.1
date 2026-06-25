#include <stdio.h>

typedef struct {
    int M[3][3];
} Tabuleiro;

void desenha() {

    Tabuleiro tabuleiro = {{
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    }};

    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char simbolo = ' ';

            if (tabuleiro.M[i][j] == 4) {
                simbolo = 'X';
            } else if (tabuleiro.M[i][j] == 1) {
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

int marcaJogada(int x, int y, int tipo) {
    return 0;
}