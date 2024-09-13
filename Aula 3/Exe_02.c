#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int *v = NULL;
    int n = 0;
    char opcao;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    do {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);

        v = (int *) realloc(v, n * sizeof(int));
        if (v == NULL) {
            printf("Erro de alocação de memória\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            v[i] = rand() % 100; // Números aleatórios entre 0 e 99
        }

        imprimeVetor(v, n);

        printf("Deseja continuar? (s/n) ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    free(v); // Libera a memória alocada

    return 0;
}