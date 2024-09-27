#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q4.h"

struct no {
    char nome[MAX];
    int numPessoas;
    No *prox;
};

struct fila {
    int qtd;
    No *inicio;
    No *fim;
};

Fila* criaFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    if (!f)
        return NULL;

    f -> qtd = 0;
    f -> inicio = NULL;
    f -> fim = NULL;
}

No *adicionarCliente(Fila *f, char nome[], int numPessoas) {
    No *novo = (No *) malloc(sizeof(No));
    if (!novo)
        return NULL;
    
    strcpy(novo -> nome, nome);
    novo -> numPessoas = numPessoas;
    novo -> prox = NULL;

    if (f -> qtd == 0) {
        f -> inicio = novo;
        f -> fim = novo;
    } else {
        f -> fim -> prox = novo;
        f -> fim = novo;
    }

    f -> qtd ++;

    return novo;
}

int atenderCliente(Fila *f) {
    if (f -> qtd == 0)
        return 0;

    No *aux = f -> inicio;
    f -> inicio = f -> inicio -> prox;
    free(aux);
    f -> qtd --;

    return 1;
}

int TamanhoFila(Fila *f) {
    return f -> qtd;
}

const char *ClienteTopo(Fila *f) {
    if (f -> qtd == 0)
        return NULL;

    return f -> inicio -> nome;
}

int TotalClientesTopo(Fila *f) {
    if (f -> qtd == 0)
        return 0;
    
    return f -> inicio -> numPessoas;
}

void desalocaFila(Fila *f) {
    while (f -> inicio != NULL) {
        atenderCliente(f);
    }

    No *aux = f -> inicio;
    while (aux != NULL) {
        f -> inicio = f -> inicio -> prox;
        free(aux);
    }

    free(f);
}