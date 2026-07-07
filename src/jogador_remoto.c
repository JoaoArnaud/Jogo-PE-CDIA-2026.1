#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../include/jogador_remoto.h"
#include "../include/tabuleiro.h"

// accept(porta) do modelo cliente-servidor:
// cria o ServerSocket, faz bind na porta, escuta e espera o cliente conectar.
void aceita(JogadorRemoto *jogador, int porta) {
    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    // Cria socket de escuta
    jogador->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (jogador->serverSocket < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Permite reusar a porta logo apos fechar (evita "Address already in use")
    int reuso = 1;
    setsockopt(jogador->serverSocket, SOL_SOCKET, SO_REUSEADDR, &reuso, sizeof(reuso));

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    // Associa socket a porta
    if (bind(jogador->serverSocket, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro no bind");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    // Escuta conexoes
    if (listen(jogador->serverSocket, 1) < 0) {
        perror("Erro no listen");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Aguardando conexao do outro jogador na porta %d...\n", porta);

    // accept() e bloqueante: espera o cliente e cria o socket de comunicacao
    jogador->socket = accept(jogador->serverSocket, (struct sockaddr *)&endereco, &endereco_len);
    if (jogador->socket < 0) {
        perror("Erro no accept");
        close(jogador->serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Jogador conectado!\n");
}

// conecta(ip, porta): cria o Socket e pede conexao ao servidor.
void conecta(JogadorRemoto *jogador, const char *ip, int porta) {
    struct sockaddr_in servidor;

    // Cria socket
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

    // Conecta ao servidor
    if (connect(jogador->socket, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        perror("Erro ao conectar");
        close(jogador->socket);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao outro jogador!\n");
}

// Envia o numero da jogada para o processo remoto.
void enviaJogada(JogadorRemoto *jogador, int numero) {
    send(jogador->socket, &numero, sizeof(numero), 0);
}

// joga() do JogadorRemoto: fica bloqueado no recv esperando a jogada
// enviada pelo processo remoto e, ao receber, atualiza o Tabuleiro.
void jogaRemoto(JogadorRemoto *jogador, Tabuleiro *tabuleiro) {
    int numero;

    int bytes = recv(jogador->socket, &numero, sizeof(numero), 0);
    if (bytes <= 0) {
        printf("O outro jogador desconectou.\n");
        exit(EXIT_FAILURE);
    }

    marcaJogada(tabuleiro, numero, jogador->tipo);
}
