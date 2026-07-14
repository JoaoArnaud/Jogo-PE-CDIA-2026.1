#include "../include/regra_IA.h"
#include "../include/tabuleiro.h"

// As 8 combinações que vencem o jogo, na numeração 1-9 do tabuleiro.
static const int LINHAS[8][3] = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
    {1, 4, 7}, {2, 5, 8}, {3, 6, 9},
    {1, 5, 9}, {3, 5, 7}
};

static int valor(Tabuleiro *tabuleiro, int pos) {
    int contador = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (contador == pos) {
                return tabuleiro->M[i][j];
            }

            contador++;
        }
    }

    return DESCONHECIDO;
}

static int livre(Tabuleiro *tabuleiro, int pos) {
    return valor(tabuleiro, pos) == DESCONHECIDO;
}

// Marca "pos" com "tipo", checa se venceu, desfaz a marcação e devolve o resultado.
static int vence(Tabuleiro *tabuleiro, int pos, EstadoJogo tipo) {
    int contador = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (contador == pos) {
                tabuleiro->M[i][j] = tipo;
                int venceu = (temVencedor(tabuleiro) == tipo);
                tabuleiro->M[i][j] = DESCONHECIDO;
                return venceu;
            }

            contador++;
        }
    }

    return 0;
}

// Conta quantas linhas têm duas marcas de "tipo" e uma posição vazia.
static int ameacas(Tabuleiro *tabuleiro, EstadoJogo tipo) {
    int total = 0;

    for (int i = 0; i < 8; i++) {
        int a = valor(tabuleiro, LINHAS[i][0]);
        int b = valor(tabuleiro, LINHAS[i][1]);
        int c = valor(tabuleiro, LINHAS[i][2]);

        int marcas = (a == tipo) + (b == tipo) + (c == tipo);
        int vazios = (a == DESCONHECIDO) + (b == DESCONHECIDO) + (c == DESCONHECIDO);

        if (marcas == 2 && vazios == 1) {
            total++;
        }
    }

    return total;
}

// Marca "pos" com "tipo" e verifica se isso cria duas ameaças ao mesmo tempo.
static int criaFork(Tabuleiro *tabuleiro, int pos, EstadoJogo tipo) {
    int contador = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (contador == pos) {
                tabuleiro->M[i][j] = tipo;
                int total = ameacas(tabuleiro, tipo);
                tabuleiro->M[i][j] = DESCONHECIDO;
                return total >= 2;
            }

            contador++;
        }
    }

    return 0;
}

int decideJogada(Tabuleiro *tabuleiro, EstadoJogo tipoIA, EstadoJogo tipoAdversario) {
    int cantos[]  = {1, 3, 7, 9};
    int opostos[] = {9, 7, 3, 1}; // oposto de cantos[i]

    // R1: vencer ou bloquear.
    for (int p = 1; p <= 9; p++) {
        if (livre(tabuleiro, p) && vence(tabuleiro, p, tipoIA)) {
            return p;
        }
    }
    for (int p = 1; p <= 9; p++) {
        if (livre(tabuleiro, p) && vence(tabuleiro, p, tipoAdversario)) {
            return p;
        }
    }

    // R2: jogada que cria duas ameaças ao mesmo tempo (fork).
    for (int p = 1; p <= 9; p++) {
        if (livre(tabuleiro, p) && criaFork(tabuleiro, p, tipoIA)) {
            return p;
        }
    }

    // R3: centro.
    if (livre(tabuleiro, 5)) {
        return 5;
    }

    // R4: canto oposto ao do adversário.
    for (int i = 0; i < 4; i++) {
        if (valor(tabuleiro, cantos[i]) == tipoAdversario && livre(tabuleiro, opostos[i])) {
            return opostos[i];
        }
    }

    // R5: qualquer canto livre.
    for (int i = 0; i < 4; i++) {
        if (livre(tabuleiro, cantos[i])) {
            return cantos[i];
        }
    }

    // R6: qualquer posição livre.
    for (int p = 1; p <= 9; p++) {
        if (livre(tabuleiro, p)) {
            return p;
        }
    }

    return 0; // não deve acontecer se ainda há posições livres
}