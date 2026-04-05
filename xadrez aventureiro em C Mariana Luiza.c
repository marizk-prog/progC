#include <stdio.h>

int main() {

    // =========================
    // TORRE (FOR)
    // =========================
    int casasTorre = 5;

    printf("Movimento da Torre:\n");

    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    // =========================
    // BISPO (WHILE)
    // =========================
    int casasBispo = 5;
    int contadorBispo = 0;

    printf("\nMovimento do Bispo:\n");

    while (contadorBispo < casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // =========================
    // RAINHA (DO-WHILE)
    // =========================
    int casasRainha = 8;
    int contadorRainha = 0;

    printf("\nMovimento da Rainha:\n");

    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    // =========================
    // CAVALO (LOOPS ANINHADOS)
    // =========================
    // Movimento: 2 Baixo + 1 Esquerda

    int movimentosBaixo = 2;

    printf("\nMovimento do Cavalo:\n");

    for (int i = 0; i < movimentosBaixo; i++) {
        printf("Baixo\n");

        // Após completar o segundo "Baixo", executa "Esquerda"
        if (i == movimentosBaixo - 1) {
            int contador = 0;

            while (contador < 1) {
                printf("Esquerda\n");
                contador++;
            }
        }
    }

    return 0;
}