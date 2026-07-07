# Jogo da Velha - PE/CDIA 2026.1

Este repositório contém o projeto de um **Jogo da Velha** desenvolvido em linguagem **C** para a disciplina de **Programação Estruturada**, do curso de **Ciência de Dados e Inteligência Artificial** da **UFPB (Universidade Federal da Paraíba)**.

O trabalho faz parte das atividades do **2º período**, no semestre **2026.1**.

## Desenvolvedores

| Nome | GitHub |
| --- | --- |
| João André de Medeiros Arnaud | [@JoaoArnaud](https://github.com/JoaoArnaud) |
| Eduardo Antônio Leitão do Oliveira Lima e Moura Filho | [@EduardoLeitaoFilho](https://github.com/EduardoLeitaoFilho) |

## Sobre o projeto

O projeto consiste na implementação de um jogo da velha utilizando os conceitos estudados na disciplina de Programação Estruturada.

## Estrutura do projeto

| Pasta | Descrição |
| --- | --- |
| `src/` | Contém o código-fonte do projeto, ou seja, os arquivos `.c`. |
| `include/` | Contém os arquivos de cabeçalho `.h`, usados para declarar funções, constantes e estruturas compartilhadas entre os arquivos `.c`. |

## Como compilar

O projeto gera três executáveis (na pasta `build/`), compilados diretamente com o `gcc`:

```bash
mkdir -p build

# Menu com o modo local (dois jogadores no mesmo teclado):
gcc src/main.c src/menu.c src/partida.c src/jogador_teclado.c src/jogador_remoto.c src/tabuleiro.c -o build/jogo-da-velha

# Modo online - servidor (jogador X):
gcc src/main_servidor.c src/jogador_teclado.c src/jogador_remoto.c src/tabuleiro.c -o build/servidor

# Modo online - cliente (jogador O):
gcc src/main_cliente.c src/jogador_teclado.c src/jogador_remoto.c src/tabuleiro.c -o build/cliente
```

| Executável | Descrição |
| --- | --- |
| `build/jogo-da-velha` | Menu com o modo local (dois jogadores no mesmo teclado). |
| `build/servidor` | Modo online: jogador **X**, que espera a conexão e começa a partida. |
| `build/cliente` | Modo online: jogador **O**, que se conecta ao servidor. |

Para limpar os binários, basta apagar a pasta: `rm -rf build`.

## Como jogar o modo online (socket)

O modo 3 usa dois programas separados que se comunicam por sockets TCP:

1. Em um computador, inicie o **servidor** (jogador X, começa jogando):

   ```bash
   ./build/servidor
   ```

2. No outro computador, inicie o **cliente** (jogador O) informando o IP do
   servidor. No mesmo computador, o IP padrão `127.0.0.1` já é usado:

   ```bash
   ./build/cliente 192.168.0.10   # IP do servidor
   ./build/cliente                # mesmo computador (127.0.0.1)
   ```

Depois de conectados, as jogadas são intercaladas (X começa) até que alguém
vença ou o jogo termine em empate. A porta usada é a `8080`.

## Cronograma

| Data | Atividade |
| --- | --- |
| 18/06/2026 | Teoria da primeira entrega |
| 25/06/2026 | Teoria da segunda entrega |
| 30/06/2026 | Primeira entrega do trabalho |
| 02/07/2026 | Teoria da terceira entrega |
| 07/07/2026 | Entrega final do trabalho: entrega 2 e entrega 3 |

## Tecnologias

- Linguagem C
- Compilador C, como GCC
