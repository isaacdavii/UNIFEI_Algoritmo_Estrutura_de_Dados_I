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
} Tpilha;

Tpilha *criaPilha() {
    Tpilha *pilha = (Tpilha *) malloc(sizeof(Tpilha));
    if (!pilha)
        return NULL;
    
    pilha -> topo = NULL;
    pilha -> qtd = 0;

    return pilha;
}

int push(Tpilha *pilha, char valor) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (!novo)
        return NULL;

    novo -> valor = valor;
    novo -> prox = pilha -> topo;

    pilha -> topo = novo;
    pilha -> qtd++;

    return 1;
}

int percorrePilha(Tpilha *pilha) {
    TNo *aux = pilha -> topo;
    while (aux != NULL) {
        printf("%c\n", aux -> valor);
        aux = aux -> prox;
    }
}

void desalocaPilha(Tpilha *pilha) {
    while (pilha -> topo != NULL) {
        TNo *aux = pilha -> topo;
        pilha -> topo = aux -> prox;
        free(aux);
    }
    free(pilha);
}

