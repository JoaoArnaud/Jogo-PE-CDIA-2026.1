#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../include/tabuleiro.h"
#include "../include/jogador_teclado.h"
#include "../include/jogador_remoto.h"

#define PORTA 8080

// Jogador servidor: espera a conexao, joga com X e comeca a partida.
int main() {
    Tabuleiro tabuleiro = {0};

    JogadorTeclado local = { .tipo = JOGADOR_X };      // este processo joga com X
    JogadorRemoto adversario = { .tipo = JOGADOR_O };  // o cliente joga com O

    printf("=== Jogo da Velha - Servidor (você é o jogador X) ===\n");

    // accept(porta): cria o ServerSocket e espera o cliente conectar
    aceita(&adversario, PORTA);

    EstadoJogo resultado = DESCONHECIDO;
    bool vezLocal = true;   // o servidor (X) comeca

    desenha(&tabuleiro);

    while (resultado == DESCONHECIDO) {
        if (vezLocal) {
            printf("--- Sua vez (X) ---\n");
            joga(local, &tabuleiro, &adversario);   // le do teclado, marca e envia
            vezLocal = false;
        } else {
            printf("Aguardando jogada do adversário...\n");
            jogaRemoto(&adversario, &tabuleiro);     // bloqueia ate receber e marca
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
