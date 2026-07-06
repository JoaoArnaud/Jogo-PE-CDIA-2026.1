#include "../include/partida.h"

int main() {
    Partida partida = {0};

    configuraJogadores(&partida);
    inicia(&partida);

    return 0;
}
