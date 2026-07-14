#ifndef MENU_H
#define MENU_H

typedef enum {
    MODO_INVALIDO = 0,
    MODO_DOIS_JOGADORES = 1,
    MODO_IA = 2,
    MODO_SOCKET = 3
} ModoJogo;

void exibeMenu(ModoJogo *modo);

#endif