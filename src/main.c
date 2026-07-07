#include <stdio.h>
#include "../include/menu.h"
#include "../include/partida.h"

int main() {
    ModoJogo modo;
    exibeMenu(&modo);

    Partida partida = {0};

    switch (modo) {
        case MODO_DOIS_JOGADORES:
            configuraJogadores(&partida);
            inicia(&partida);
            break;

        case MODO_IA:
            printf("\nModo Jogador vs IA ainda em desenvolvimento.\n");
            break;

        case MODO_SOCKET:
            printf("\nModo online (socket): use os dois programas separados.\n");
            break;

        default:
            printf("Opção inválida.\n");
    }

    return 0;
}