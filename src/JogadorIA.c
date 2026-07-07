#include <stdio.h>
#include "../include/JogadorIA.h"
#include "../include/regra_IA.h"
#include "../include/tabuleiro.h"
 
void jogaIA(JogadorIA jogador, Tabuleiro *tabuleiro) {
    EstadoJogo adversario = (jogador.tipo == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
 
    int numero = decideJogada(tabuleiro, jogador.tipo, adversario);
 
    printf("IA jogou na posição %d.\n", numero);
    marcaJogada(tabuleiro, numero, jogador.tipo);
}