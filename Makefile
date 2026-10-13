# Makefile - Desafio 4: Clique no alvo (Fedora / Linux)
CC     = gcc
CFLAGS = -Wall -std=c99
LIBS   = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC    = Jogo.c
BIN    = jogo

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(LIBS)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean