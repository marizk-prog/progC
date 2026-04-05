#include <stdio.h>

// ==========================================
// FUNÇÃO RECURSIVA DA TORRE
// Move 5 casas para a direita
// ==========================================
void moverTorre(int casas) {
    if (casas <= 0) {
        return;
    }

    printf("Direita\n");
    moverTorre(casas - 1);
}

// ==========================================
// FUNÇÃO RECURSIVA DO BISPO
// Usa recursividade + loops aninhados
// Loop externo = vertical
// Loop interno = horizontal
// Movimento: 5 casas na diagonal para cima e direita
// ==========================================
void moverBispo(int casas) {
    if (casas <= 0) {
        return;
    }

    // Loops aninhados: externo vertical, interno horizontal
    for (int vertical = 0; vertical < 1; vertical++) {
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima Direita\n");
        }
    }

    moverBispo(casas - 1);
}

// ==========================================
// FUNÇÃO RECURSIVA DA RAINHA
// Move 8 casas para a esquerda
// ==========================================
void moverRainha(int casas) {
    if (casas <= 0) {
        return;
    }

    printf("Esquerda\n");
    moverRainha(casas - 1);
}

int main() {
    // Quantidade de casas de cada peça
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // ==========================================
    // TORRE
    // ==========================================
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // ==========================================
    // BISPO
    // ==========================================
    printf("\nMovimento do Bispo:\n");
    moverBispo(casasBispo);

    // ==========================================
    // RAINHA
    // ==========================================
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // ==========================================
    // CAVALO
    // Movimento em L:
    // 2 casas para cima + 1 casa para a direita
    // Usando loops aninhados com controle break/continue
    // ==========================================
    printf("\nMovimento do Cavalo:\n");

    for (int vertical = 1; vertical <= 2; vertical++) {
        // imprime as duas casas para cima
        printf("Cima\n");

        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            // enquanto ainda não terminou o movimento vertical,
            // não executa o movimento horizontal
            if (vertical < 2) {
                continue;
            }

            printf("Direita\n");
            break;
        }
    }

    return 0;
}