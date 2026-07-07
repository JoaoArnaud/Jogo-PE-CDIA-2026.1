#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../include/tabuleiro.h"
#include "../include/jogador_teclado.h"
#include "../include/jogador_remoto.h"

#define PORTA 8080

int main(int argc, char *argv[]) {
    const char *ip = (argc > 1) ? argv[1] : "127.0.0.1";

    Tabuleiro tabuleiro = {0};

    JogadorTeclado local = { .tipo = JOGADOR_O };
    JogadorRemoto adversario = { .tipo = JOGADOR_X };

    printf("=== Jogo da Velha - Cliente (você é o jogador O) ===\n");

    conecta(&adversario, ip, PORTA);

    EstadoJogo resultado = DESCONHECIDO;
    bool vezLocal = false;

    desenha(&tabuleiro);

    while (resultado == DESCONHECIDO) {
        if (vezLocal) {
            printf("--- Sua vez (O) ---\n");
            joga(local, &tabuleiro, &adversario);
            vezLocal = false;
        } else {
            printf("Aguardando jogada do adversário...\n");
            jogaRemoto(&adversario, &tabuleiro);
            vezLocal = true;
        }

        resultado = temVencedor(&tabuleiro);
    }

    if (resultado == JOGADOR_O) {
        printf("Você (O) venceu!\n");
    } else if (resultado == JOGADOR_X) {
        printf("Você (O) perdeu!\n");
    } else {
        printf("Empate!\n");
    }

    close(adversario.socket);
    return 0;
}
