#include <stdio.h>

int tabuleiro[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void desenha() {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char simbolo = ' ';

            if (tabuleiro[i][j] == 1) {
                simbolo = 'X';
            } else if (tabuleiro[i][j] == 2) {
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
