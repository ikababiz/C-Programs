#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 20
#define COLS 10
#define TAM 25 

int piezas[7][4][4] = {
    {{1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,1,1,0}, {1,0,0,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,1,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}}
};

int tablero[FILAS][COLS] = {0};

void dibujarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            int x1 = j * TAM + 50, y1 = i * TAM + 50;
            if (tablero[i][j] == 0) {
                setcolor(DARKGRAY);
                rectangle(x1, y1, x1 + TAM, y1 + TAM);
            } else {
                setfillstyle(SOLID_FILL, CYAN);
                bar(x1 + 1, y1 + 1, x1 + TAM - 1, y1 + TAM - 1);
            }
        }
    }
}

void dibujarPieza(int p, int x, int y) {
    setfillstyle(SOLID_FILL, YELLOW);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piezas[p][i][j]) {
                int px = (x + j) * TAM + 50;
                int py = (y + i) * TAM + 50;
                bar(px + 1, py + 1, px + TAM - 1, py + TAM - 1);
            }
        }
    }
}

bool validarMovimiento(int p, int nx, int ny) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piezas[p][i][j]) {
                int tx = nx + j;
                int ty = ny + i;
                if (tx < 0 || tx >= COLS || ty >= FILAS || (ty >= 0 && tablero[ty][tx]))
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int gd = DETECT, gm;
    initwindow(400, 600, "Tetris Graphics.h");
    srand(time(NULL));

    int px = 3, py = 0, tipo = rand() % 7;
    int delay_count = 0;

    while (true) {
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'a' && validarMovimiento(tipo, px - 1, py)) px--;
            if (tecla == 'd' && validarMovimiento(tipo, px + 1, py)) px++;
            if (tecla == 's' && validarMovimiento(tipo, px, py + 1)) py++;
            if (tecla == 27) break;
        }

        if (delay_count > 10) {
            if (validarMovimiento(tipo, px, py + 1)) {
                py++;
            } else {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (piezas[tipo][i][j]) tablero[py + i][px + j] = 1;
                
                px = 3; py = 0; tipo = rand() % 7;
                if (!validarMovimiento(tipo, px, py)) break;
            }
            delay_count = 0;
        }

        cleardevice();
        dibujarTablero();
        dibujarPieza(tipo, px, py);
        delay(30);
        delay_count++;
    }

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100, 250, (char*)"GAME OVER");
    getch();
    closegraph();
    return 0;
}