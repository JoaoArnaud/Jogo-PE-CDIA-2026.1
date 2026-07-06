#ifndef TABULEIRO_H
#define TABULEIRO_H

void desenha();
void desenhaSemNumeros();
int temVencedor();
int marcaJogada(int x, int y, int tipo);
int marcaJogadaPorNumero(int numero, int tipo);

#endif
