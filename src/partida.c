#include <stdio.h>
#include "../include/partida.h"
#include "jogador_teclado.h"
#include "../include/tabuleiro.h"

typedef struct {
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
} Partida;

static Partida partida;

void configuraJogadores() {
    partida.jogador1.tipo = 1;
    partida.jogador2.tipo = 4;
}

void inicia() {
    int resultado = 0;
    int vez = 1;

    desenha();

    while (resultado == 0) {
        if (vez == 1) {
            joga(partida.jogador1);
            vez = 2;
        } else {
            joga(partida.jogador2);
            vez = 1;
        }

        resultado = temVencedor();
    }

    desenhaSemNumeros();

    if (resultado == 1) {
        printf("Jogador 1 venceu!\n");
    } else if (resultado == 4) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}
