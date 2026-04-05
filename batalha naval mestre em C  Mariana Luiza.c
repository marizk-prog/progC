#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // ================================
    // Inicializa tabuleiro com água
    // ================================
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ================================
    // NAVIOS (mesmo do nível anterior)
    // ================================

    // Horizontal
    for (i = 0; i < 3; i++)
        tabuleiro[1][2 + i] = NAVIO;

    // Vertical
    for (i = 0; i < 3; i++)
        tabuleiro[4 + i][7] = NAVIO;

    // Diagonal principal
    for (i = 0; i < 3; i++)
        tabuleiro[6 + i][1 + i] = NAVIO;

    // Diagonal secundária
    for (i = 0; i < 3; i++)
        tabuleiro[0 + i][9 - i] = NAVIO;

    // ================================
    // MATRIZES DE HABILIDADE
    // ================================

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int meio = TAM_HAB / 2;

    // ================================
    // CONE (expande para baixo)
    // ================================
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ================================
    // CRUZ
    // ================================
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ================================
    // OCTAEDRO (LOSANGO)
    // ================================
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ================================
    // POSIÇÃO DAS HABILIDADES NO TABULEIRO
    // ================================

    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctLinha = 7, origemOctColuna = 3;

    // ================================
    // FUNÇÃO DE SOBREPOSIÇÃO (manual)
    // ================================

    // CONE
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {

            int linha = origemConeLinha + (i - meio);
            int coluna = origemConeColuna + (j - meio);

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // CRUZ
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {

            int linha = origemCruzLinha + (i - meio);
            int coluna = origemCruzColuna + (j - meio);

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // OCTAEDRO
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {

            int linha = origemOctLinha + (i - meio);
            int coluna = origemOctColuna + (j - meio);

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // ================================
    // EXIBIÇÃO DO TABULEIRO
    // ================================
    printf("Legenda: 0=Agua | 3=Navio | 5=Habilidade\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}