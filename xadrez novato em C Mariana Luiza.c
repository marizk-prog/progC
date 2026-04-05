#include <stdio.h>

int main() {

    // =========================
    // TORRE (usando FOR)
    // =========================
    // Movimento: 5 casas para a direita

    int casasTorre = 5;

    printf("Movimento da Torre:\n");

    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    // =========================
    // BISPO (usando WHILE)
    // =========================
    // Movimento: 5 casas na diagonal (Cima + Direita)

    int casasBispo = 5;
    int contadorBispo = 0;

    printf("\nMovimento do Bispo:\n");

    while (contadorBispo < casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // =========================
    // RAINHA (usando DO-WHILE)
    // =========================
    // Movimento: 8 casas para a esquerda

    int casasRainha = 8;
    int contadorRainha = 0;

    printf("\nMovimento da Rainha:\n");

    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    return 0;
}
// Eu utilizei uma estrutura de repetição diferente para cada peça, conforme solicitado: for para a Torre, while para o Bispo e do-while para a Rainha, respeitando a lógica de movimento de cada uma.