#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../include/tabuleiro.h"
#include "../include/jogador_teclado.h"
#include "../include/jogador_remoto.h"

#define PORTA 8080

int main() {
    Tabuleiro tabuleiro = {0};

    JogadorTeclado local = { .tipo = JOGADOR_X };
    JogadorRemoto adversario = { .tipo = JOGADOR_O };

    printf("=== Jogo da Velha - Servidor (você é o jogador X) ===\n");

    aceita(&adversario, PORTA);

    EstadoJogo resultado = DESCONHECIDO;
    bool vezLocal = true;

    desenha(&tabuleiro);

    while (resultado == DESCONHECIDO) {
        if (vezLocal) {
            printf("--- Sua vez (X) ---\n");
            joga(local, &tabuleiro, &adversario);
            vezLocal = false;
        } else {
            printf("Aguardando jogada do adversário...\n");
            jogaRemoto(&adversario, &tabuleiro);
            vezLocal = true;
        }

        resultado = temVencedor(&tabuleiro);
    }

    if (resultado == JOGADOR_X) {
        printf("Voce (X) venceu!\n");
    } else if (resultado == JOGADOR_O) {
        printf("Voce (X) perdeu!\n");
    } else {
        printf("Empate!\n");
    }

    close(adversario.socket);
    close(adversario.serverSocket);
    return 0;
}
