#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int i, j;
    int valido = 1;

    // ================================
    // Inicialização do tabuleiro com água
    // ================================
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ================================
    // Coordenadas iniciais dos 4 navios
    // ================================

    // Navio 1 - horizontal
    int linhaH = 1, colunaH = 2;

    // Navio 2 - vertical
    int linhaV = 4, colunaV = 7;

    // Navio 3 - diagonal principal (linha e coluna aumentam)
    int linhaD1 = 6, colunaD1 = 1;

    // Navio 4 - diagonal secundária (linha aumenta e coluna diminui)
    int linhaD2 = 0, colunaD2 = 9;

    // ================================
    // Validação de limites
    // ================================

    // Horizontal
    if (linhaH < 0 || linhaH >= TAM_TABULEIRO || colunaH < 0 || colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites.\n");
        valido = 0;
    }

    // Vertical
    if (linhaV < 0 || linhaV + TAM_NAVIO > TAM_TABULEIRO || colunaV < 0 || colunaV >= TAM_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites.\n");
        valido = 0;
    }

    // Diagonal principal
    if (linhaD1 < 0 || linhaD1 + TAM_NAVIO > TAM_TABULEIRO || colunaD1 < 0 || colunaD1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio diagonal principal fora dos limites.\n");
        valido = 0;
    }

    // Diagonal secundária
    if (linhaD2 < 0 || linhaD2 + TAM_NAVIO > TAM_TABULEIRO || colunaD2 < 0 || colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: navio diagonal secundaria fora dos limites.\n");
        valido = 0;
    }

    // ================================
    // Posiciona navio horizontal
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                printf("Erro: sobreposicao no navio horizontal.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // ================================
    // Posiciona navio vertical
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                printf("Erro: sobreposicao no navio vertical.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // ================================
    // Posiciona navio diagonal principal
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
                printf("Erro: sobreposicao no navio diagonal principal.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // ================================
    // Posiciona navio diagonal secundaria
    // ================================
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
                printf("Erro: sobreposicao no navio diagonal secundaria.\n");
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // ================================
    // Exibe o tabuleiro completo
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