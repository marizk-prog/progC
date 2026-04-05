#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Vetores que representam os navios
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios
    // Navio horizontal começa na linha 2, coluna 4
    int linhaH = 2, colunaH = 4;

    // Navio vertical começa na linha 5, coluna 1
    int linhaV = 5, colunaV = 1;

    int i, j;
    int valido = 1;

    // Inicializa todo o tabuleiro com 0 (água)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ================================
    // Validação do navio horizontal
    // ================================
    if (linhaH < 0 || linhaH >= TAM_TABULEIRO || colunaH < 0 || colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        valido = 0;
    }

    // ================================
    // Validação do navio vertical
    // ================================
    if (linhaV < 0 || linhaV + TAM_NAVIO > TAM_TABULEIRO || colunaV < 0 || colunaV >= TAM_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        valido = 0;
    }

    // ================================
    // Posiciona o navio horizontal
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                printf("Erro: sobreposição detectada no navio horizontal.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // ================================
    // Posiciona o navio vertical
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                printf("Erro: sobreposição detectada no navio vertical.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // ================================
    // Exibe o tabuleiro
    // ================================
    if (valido) {
        printf("Tabuleiro Batalha Naval:\n\n");

        for (i = 0; i < TAM_TABULEIRO; i++) {
            for (j = 0; j < TAM_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
