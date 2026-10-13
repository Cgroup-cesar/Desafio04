# Clique no Alvo

Jogo feito em C com a [Raylib](https://www.raylib.com/) para o Desafio 4 de Programação Imperativa e Funcional (PIF) · CESAR School.

## Como jogar

Um alvo vermelho aparece na tela. Clique nele o mais rápido que conseguir antes que os **30 segundos** acabem.

| Ação | O que acontece |
|---|---|
| Clicar **dentro** do alvo | +1 ponto, o alvo encolhe um pouco e muda de lugar |
| Clicar **fora** do alvo | Nada acontece (não ganha nem perde ponto) |
| Tempo chegar a 0 | Aparece **"Fim! Pontos: N"** |
| Apertar **R** no fim | Reinicia a partida |
| Apertar **ESC** ou fechar a janela | Sai do jogo |

Na tela você vê o **tempo restante** (canto esquerdo) e os **pontos** (canto direito).

O alvo começa com raio 40 e perde 2 pixels a cada acerto, parando em 10. Quanto mais você acerta, mais difícil fica.

## Como compilar e rodar

Pré-requisito: a Raylib instalada (veja a seção abaixo).

```bash
make        # compila
make run    # compila (se precisar) e executa
make clean  # apaga o executável
```

Sem o Makefile, o comando equivalente é:

```bash
gcc Jogo.c -o jogo -Wall -std=c99 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./jogo
```

> As bibliotecas `-l...` precisam vir **depois** do arquivo `.c`.
