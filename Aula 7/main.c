#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main () {
    int valor;
    Tfila *fila = criarFila();

    if (!fila) {
        printf("Erro de alocação\n");
        return 1;
    }

    printf("Digite o valor ou -1 para encerrar");
    scanf("%d", &valor);

    while (valor != -1) {
        enfileirar(fila, valor);

        if (!enfileirar(fila, valor)) {
            printf("Erro de alocação\n");
            return 1;
        }

        printf("Digite o valor ou -1 para encerrar");
        scanf("%d", &valor);
    }

    valor = desenfileirar(fila);
    while (valor != -1) {
        printf("%d\n", valor);
        valor = desenfileirar(fila);
    }

    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    inicio(fila);
    final(fila);  

    while (!filaVazia(fila)) {
        printf("%d\n", desenfileirar(fila));
    }

    remove(fila);

    free(fila);

    return 0;
}
