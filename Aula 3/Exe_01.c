#include <stdio.h>
#include <stdlib.h>

void imprimirValoresComuns(int v1[], int n1, int v2[], int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                printf("%d ", v1[i]);
                break; // Evitar impressões duplicadas
            }
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;

    // PRIMEIRO VETOR
    printf("Digite o numero de elementos do primeiro vetor: ");
    scanf("%d", &n1);
    int *v1 = (int *) malloc(n1 * sizeof(int));

    printf("Digite os elementos do primeiro vetor: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &v1[i]);
    }

    // SEGUNDO VETOR
    printf("Digite o numero de elementos do segundo vetor: ");
    scanf("%d", &n2);
    int *v2 = (int *) malloc(n2 * sizeof(int));

    printf("Digite os elementos do segundo vetor: ");
    for (int j = 0; j < n2; j++) {
        scanf("%d", &v2[j]);
    }

    printf("Valores comuns: ");
    imprimirValoresComuns(v1, n1, v2, n2);

    free(v1);
    free(v2);

    return 0;
}