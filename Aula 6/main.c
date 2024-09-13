#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

int main () {
    int valor;
    pDin *pilha = criaPilha();

    if (!pilha) {
        printf("Erro de alocação\n");
        return 1;
    }

    printf("Digite o valor ou -1 para encerrar");
    scanf("%d", &valor);

    while (valor != -1) {
        push(pilha, valor);

        if (!push(pilha, valor)) {
            printf("Erro de alocação\n");
            return 1;
        }
        printf("Digite o valor ou -1 para encerrar");
        scanf("%d", &valor);
    }

    while (!pilhaVazia(pilha)) {
        printf("%d\n", pop(pilha));
    }

    desalocaPilha(pilha);

    return 0;
}