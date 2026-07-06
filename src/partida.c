#include <stdio.h>
#include "../include/partida.h"
#include "../include/jogador_teclado.h"
#include "../include/tabuleiro.h"

typedef struct {
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    Tabuleiro tabuleiro;
} Partida;

static Partida partida;

void configuraJogadores() {
    partida.jogador1.tipo = 1;
    partida.jogador2.tipo = 4;
}

void inicia() {
    EstadoJogo resultado = DESCONHECIDO;
    int vez = 1;

    desenha(&partida.tabuleiro);

    while (resultado == DESCONHECIDO) {
        if (vez == 1) {
            joga(partida.jogador1, &partida.tabuleiro);
            vez = 2;
        } else {
            joga(partida.jogador2, &partida.tabuleiro);
            vez = 1;
        }

        resultado = temVencedor(&partida.tabuleiro);
    }

    if (resultado == 1) {
        printf("Jogador 1 venceu!\n");
    } else if (resultado == 4) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}
