#include <stdio.h>
#include <stdbool.h>
#include "../include/jogador_teclado.h"
#include "../include/tabuleiro.h"

void joga(JogadorTeclado jogador, Tabuleiro *tabuleiro) {
    int numero;
    int numeroJogador;
    if (jogador.tipo == 1) {
        numeroJogador = 1;
    }
    else {
        numeroJogador = 2;
    }

    while (true) {
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

        if (!marcaJogada(tabuleiro, linha, coluna, jogador.tipo)) {
            printf("Posição já ocupada. Escolha outra.\n");
            continue;
        }

        break;
    }
}
