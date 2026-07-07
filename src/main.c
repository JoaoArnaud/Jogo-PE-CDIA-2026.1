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
            configuraJogadorIA(&partida);
            inicia(&partida);
            break;
 
        case MODO_SOCKET:
            printf("\nModo online (socket) ainda em desenvolvimento.\n");
            break;
 
        default:
            printf("Opção inválida.\n");
    }
 
    return 0;
}