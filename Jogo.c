#include "raylib.h"
#include <time.h>

#define LARGURA      800
#define ALTURA       450
#define TEMPO_JOGO   30.0f
#define RAIO_INICIAL 40.0f
#define RAIO_MINIMO  10.0f

typedef enum { JOGANDO, FIM } Estado;                                                 // telas do jogo

typedef struct {
    Vector2 pos;                                                                    // centro do alvo
    float raio;
} Alvo;

// ---------- logica: muda o estado, nao desenha ----------
void sorteiaPosicao(Alvo *alvo) {                                                   // coloca o alvo em um lugar aleatorio
    int r = (int)alvo->raio;
    alvo->pos.x = GetRandomValue(r, LARGURA - r);
    alvo->pos.y = GetRandomValue(r + 40, ALTURA - r);                                 // +40 deixa o topo livre p/ o texto
}

void iniciaPartida(Alvo *alvo, int *pontos, float *tempoRestante) {
    alvo->raio = RAIO_INICIAL;
    sorteiaPosicao(alvo);
    *pontos = 0;
    *tempoRestante = TEMPO_JOGO;
}

// ---------- desenho: so le o estado ----------
void desenhaAlvo(Alvo alvo) { DrawCircleV(alvo.pos, alvo.raio, RED); }

int main(void) {
    InitWindow(LARGURA, ALTURA, "Clique no alvo");
    SetTargetFPS(60);
    SetRandomSeed((unsigned int)time(NULL));                                      // sorteios diferentes a cada execucao

    Estado estado = JOGANDO;
    Alvo alvo;
    int pontos;
    float tempoRestante;
    iniciaPartida(&alvo, &pontos, &tempoRestante);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // 1. ENTRADA + 2. ATUALIZAR
        if (estado == JOGANDO) {
            tempoRestante -= dt;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                CheckCollisionPointCircle(GetMousePosition(), alvo.pos, alvo.raio)) {
                pontos++;
                alvo.raio -= 2;                                                              // encolhe
                if (alvo.raio < RAIO_MINIMO) alvo.raio = RAIO_MINIMO;
                sorteiaPosicao(&alvo);                                                       // muda de lugar
            }

            if (tempoRestante <= 0) estado = FIM;
        } else {
            if (IsKeyPressed(KEY_R)) {
                iniciaPartida(&alvo, &pontos, &tempoRestante);
                estado = JOGANDO;
            }
        }

        // 3. DESENHAR
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (estado == JOGANDO) {
                desenhaAlvo(alvo);
                DrawText(TextFormat("Tempo: %d", (int)tempoRestante + 1), 10, 10, 20, DARKGRAY);
                DrawText(TextFormat("Pontos: %d", pontos), 680, 10, 20, DARKGRAY);
            } else {
                DrawText(TextFormat("Fim! Pontos: %d", pontos), 250, 180, 40, MAROON);
                DrawText("R para reiniciar", 310, 240, 20, GRAY);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}