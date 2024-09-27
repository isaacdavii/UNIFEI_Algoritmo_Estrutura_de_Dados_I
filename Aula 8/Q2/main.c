#include <stdio.h>
#include <stdlib.h>
#include "teste_Q2.h"

int main() {
    int valor; 

    Tpilha *pilha = criaPilha();
    if (!pilha) {
        printf("Erro ao alocar pilha");
        return 1;
    }

    push(pilha, 'a');
    push(pilha, 'b');
    push(pilha, 'c');
    
    percorrePilha(pilha);

    desalocaPilha(pilha);

    return 0;
}