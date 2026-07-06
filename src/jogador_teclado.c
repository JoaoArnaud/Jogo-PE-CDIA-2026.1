#include <stdio.h>
#include "../include/jogador_teclado.h"
#include "../include/tabuleiro.h"

void joga(JogadorTeclado jogador) {
    int numero;
    int numeroJogador = (jogador.tipo == 1) ? 1 : 2;

    while (1) {
        printf("Jogador %d, escolha uma posição (1-9): ", numeroJogador);

        if (scanf("%d", &numero) != 1) {

            while (getchar() != '\n');
            printf("Entrada inválida. Digite um número de 1 a 9.\n");
            continue;
        }

        if (numero < 1 || numero > 9) {
            printf("Posição inválida. Escolha entre 1 e 9.\n");
            continue;
        }

        int linha  = (numero - 1) / 3;
        int coluna = (numero - 1) % 3;

        if (!marcaJogada(linha, coluna, jogador.tipo)) {
            printf("Posição já ocupada. Escolha outra.\n");
            continue;
        }

        break;
    }
}
