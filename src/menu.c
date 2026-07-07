#include <stdio.h>
#include <stdbool.h>
#include "../include/menu.h"

void exibeMenu(ModoJogo *modo) {
    int opcao;

    while (true) {
        printf("=====================================\n");
        printf("          JOGO DA VELHA\n");
        printf("=====================================\n");
        printf("1 - Dois jogadores (teclado)\n");
        printf("2 - Jogador vs IA\n");
        printf("3 - Modo online (socket)\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida. Tente novamente.\n\n");
            continue;
        }

        if (opcao < 1 || opcao > 3) {
            printf("Opção inválida. Escolha 1, 2 ou 3.\n\n");
            continue;
        }

        *modo = (ModoJogo) opcao; 
        return;
    }
}