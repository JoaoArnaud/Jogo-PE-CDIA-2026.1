#include <stdio.h>
#include "../include/jogador_teclado.h"
#include "../include/tabuleiro.h"

void joga(JogadorTeclado jogador) {
    int linha;
    int coluna;
    int numeroJogador;

    if (jogador.tipo == 1) {
        numeroJogador = 1;
    } else {
        numeroJogador = 2;
    }

    printf("Jogador %d, digite a linha: ", numeroJogador);
    scanf("%d", &linha);

    printf("Jogador %d, digite a coluna: ", numeroJogador);
    scanf("%d", &coluna);

    marcaJogada(linha - 1, coluna - 1, jogador.tipo);
}
