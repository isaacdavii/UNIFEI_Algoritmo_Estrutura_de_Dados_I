#include <stdio.h>
#include <stdlib.h>
#include "teste_Q2.h"

typedef struct no {
    char valor;
    no *prox;
} TNo;

typedef struct pilha {
    TNo *topo;
    int qtd;
} TPilha;

Tpilha *criaPilha() {
    TPilha *pilha = (TPilha *) malloc(sizeof(TPilha));
    if (!pilha)
        return NULL;

    pilha -> qtd = 0;
    pilha -> topo = NULL;

    return pilha;
}

int push(TPilha *pilha, char valor) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));

    if (novo == NULL) {
        return 0;
    }

    novo -> valor = valor;
    novo -> prox = pilha -> topo;
    pilha -> topo = novo;
    pilha -> qtd++;

    return 1;
}

int percorrePilha(TPilha *pilha) {
    TNo *aux = pilha -> topo;
    while (aux != NULL) {
        printf("%c\n", aux -> valor);
        aux = aux -> prox;
    }
}

void desalocaPilha(TPilha *pilha) {
    while (pilha -> topo != NULL) {
        TNo *aux = pilha -> topo;
        pilha -> topo = aux -> prox;
        free(aux);
    }
    free(pilha);
}

