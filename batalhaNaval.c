#include <stdio.h>

#define TAMANHO 10

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3; 
    }
    for (int i = 3; i < 6; i++) {
        tabuleiro[i][i] = 3; 
    }
    for (int i = 7; i < 10; i++) {
        tabuleiro[6][i] = 3; 
    }
    for (int i = 7; i < 10; i++) {
        tabuleiro[i][2] = 3; 
    }
}

void preencherAreasAfetadas(int tabuleiro[TAMANHO][TAMANHO], int areasAfetadas[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 3) {  
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                            if (tabuleiro[x][y] != 3) {  
                                areasAfetadas[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int areasAfetadas[TAMANHO][TAMANHO] = {0};  

    inicializarTabuleiro(tabuleiro);

    printf("Tabuleiro com navios (3):\n");
    imprimirTabuleiro(tabuleiro);

    preencherAreasAfetadas(tabuleiro, areasAfetadas);

    printf("\nTabuleiro com áreas afetadas (1) e não afetadas (0):\n");
    imprimirTabuleiro(areasAfetadas);

    return 0;
}
