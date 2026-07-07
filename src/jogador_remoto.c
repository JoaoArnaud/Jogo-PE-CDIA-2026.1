#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../include/jogador_remoto.h"
#include "../include/tabuleiro.h"

void aceita(JogadorRemoto *jogador, int porta) {
    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    jogador->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (jogador->serverSocket < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    int reuso = 1;
    setsockopt(jogador->serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuso, sizeof(reuso));

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    if (bind(jogador->serverSocket, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro no bind");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    if (listen(jogador->serverSocket, 1) < 0) {
        perror("Erro no listen");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Aguardando conexão do outro jogador na porta %d...\n", porta);

    jogador->socket = accept(jogador->serverSocket, (struct sockaddr *)&endereco, &endereco_len);
    if (jogador->socket < 0) {
        perror("Erro no accept");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Jogador conectado!\n");
}

void conecta(JogadorRemoto *jogador, const char *ip, int porta) {
    struct sockaddr_in servidor;

    jogador->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (jogador->socket < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(porta);

    if (inet_pton(AF_INET, ip, &servidor.sin_addr) <= 0) {
        perror("Endereco invalido");
        close(jogador->socket);
        exit(EXIT_FAILURE);
    }

    if (connect(jogador->socket, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        perror("Erro ao conectar");
        close(jogador->socket);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao outro jogador!\n");
}

void enviaJogada(JogadorRemoto *jogador, int numero) {
    send(jogador->socket, &numero, sizeof(numero), 0);
}

void jogaRemoto(JogadorRemoto *jogador, Tabuleiro *tabuleiro) {
    int numero;

    int bytes = recv(jogador->socket, &numero, sizeof(numero), 0);
    if (bytes <= 0) {
        printf("O outro jogador desconectou.\n");
        exit(EXIT_FAILURE);
    }

    marcaJogada(tabuleiro, numero, jogador->tipo);
}
