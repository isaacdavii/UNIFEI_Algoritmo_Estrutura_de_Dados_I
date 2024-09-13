#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

struct no {
    int valor;
    struct no *prox;
};

struct pilhaDinamica {
    no *topo;
    int qtd;
};

pDin *criaPilha() {
    pDin *pilha = (pDin *) malloc(sizeof(pDin));
    if (!pilha)
        return NULL;

    pilha -> qtd = 0;
    pilha -> topo = NULL;

    return pilha;
}

int pilhaVazia(pDin *pilha) {
    return pilha -> topo == NULL;
}

int push(pDin *pilha, int valor) {
    no *novo = (no *) malloc(sizeof(no));

    if (novo == NULL) {
        return 0;
    }

    novo-> valor = valor;
    novo -> prox = pilha -> topo;
    pilha -> topo = novo;
    pilha -> qtd++;

    return 1;
}

int pop(pDin *pilha) {
    if (pilhaVazia(pilha)) {
        return -1;
    }

    no *aux = pilha -> topo;
    int valor = aux -> valor;
    pilha -> topo = aux -> prox;
    free(aux);
    pilha -> qtd--;

    return valor;
}

void topo(pDin *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Topo: %d\n", pilha->topo->valor);
}

int qtdElementos(pDin *pilha) {
    printf("Quantidade de elementos: %d\n", pilha->qtd);
}

void esvazia(pDin *pilha) {
    while (!pilhaVazia(pilha)) {
        pop(pilha);
    }
}

void desalocaPilha(pDin *pilha) {
    esvazia(pilha);
    free(pilha);
}