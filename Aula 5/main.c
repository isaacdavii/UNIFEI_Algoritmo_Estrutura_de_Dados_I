#include <stdio.h>
#include "pilhaEst.h"

int main() {
    int tamanhoPilha;
    pEst *pilha;
    int valor;

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanhoPilha);

    pilha = criaPilha(tamanhoPilha);
    if (!pilha){
        printf("Nao foi possivel alocar a pilha!");
        return -1;
    }

    for (int i = 0; i < tamanhoPilha; i++) {
        printf("Digite o valor a ser inserido na pilha: ");
        scanf("%d", &valor);
        
        push(pilha, valor);

        if (!push(pilha, valor)) {
            printf("Pilha cheia!\n");
            break;
        }
    }

    for (int j = 0; j < tamanhoPilha; j++) {
        printf("Valor removido: %d\n", pop(pilha));
    }

    desalocaPilha(pilha);

    return 0;
}