#include <stdio.h>
#include "../include/partida.h"
#include "../include/jogador_teclado.h"
#include "../include/JogadorIA.h"
#include "../include/tabuleiro.h"
 
void configuraJogadores(Partida *partida) {
    partida->tipo = PARTIDA_DOIS_JOGADORES;
    partida->jogador1.tipo = JOGADOR_O;
    partida->jogador2.tipo = JOGADOR_X;
}
 
void configuraJogadorIA(Partida *partida) {
    partida->tipo = PARTIDA_CONTRA_IA;
    partida->jogador1.tipo = JOGADOR_O;   // jogador humano
    partida->jogadorIA.tipo = JOGADOR_X;  // IA
}
 
void inicia(Partida *partida) {
    EstadoJogo resultado = DESCONHECIDO;
    int vez = 1;
 
    desenha(&partida->tabuleiro);
 
    while (resultado == DESCONHECIDO) {
        if (vez == 1) {
            joga(partida->jogador1, &partida->tabuleiro);
            vez = 2;
        } else {
            if (partida->tipo == PARTIDA_CONTRA_IA) {
                jogaIA(partida->jogadorIA, &partida->tabuleiro);
            } else {
                joga(partida->jogador2, &partida->tabuleiro);
            }
            vez = 1;
        }
 
        resultado = temVencedor(&partida->tabuleiro);
    }
 
    if (resultado == 1) {
        printf("Jogador 1 venceu!\n");
    } else if (resultado == 4) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}