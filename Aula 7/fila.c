#include <stdio.h>
#include "fila.h"

struct no {
    int valor;
    No* prox;
};

struct fila {
    int qtdElementos;
    No* inicio;
    No* final;
};

Tfila* criarFila() {
    Tfila* fila = (Tfila*) malloc(sizeof(Tfila));
    // Declara um ponteiro chamado 'fila' do tipo 'Tfila' e aloca um espaço de memória do tamanho de 'Tfila' e guarda o endereço de memória alocado em 'fila'
    //(Tfila*) é um 'typecast', i.e, conversão explícita do valor retornado pela função malloc para o tipo 'Tfila*'
    
    fila -> qtdElementos = 0;
    fila -> inicio = NULL;
    fila -> final = NULL;

    return fila;
}

int enfileirar(Tfila* fila, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    // Declara um ponteiro chamado 'novo' do tipo 'no' e aloca um espaço de memória do tamanho de 'no' e guarda o endereço de memória alocado em 'novo'
    //(no*) é um 'typecast', i.e, conversão explícita do valor retornado pela função malloc para o tipo 'no*'
    
    if (!novo)
        return 0; // Indica que a alocação de memória falhou

    novo -> valor = valor; // O valor do nó é igual ao valor passado como parâmetro
    novo -> prox = NULL; // Indica que ele é o último nó da fila no momento da criação

    if (fila -> qtdElementos == 0) { // Se fila está vazia
        fila -> inicio = novo;
    } else {
        fila -> final -> prox = novo;
    }

    fila -> final = novo;
    fila -> qtdElementos++;

    return 1;
}

int desenfileirar(Tfila* fila) {
    if (fila -> qtdElementos == 0) {
        return 0; // Indica que a fila está vazia
    }

    No* aux = fila -> inicio; // Cria um ponteiro auxiliar que aponta para o início da fila
    int valor = aux -> valor; // Armazena o valor do primeiro elemento da fila na variável

    fila -> inicio = aux -> prox; // Cria um ponteiro que aponta para o próximo elemento da fila
    fila -> qtdElementos--; // Decrementa o contador de elementos na fila

    free(aux); // Libera a memória alocada para o nó que foi removido da fila

    return valor; // Retorna o valor do elemento que foi removido da fila
}

void inicio(Tfila* fila) {
    if (fila -> qtdElementos == 0) {
        printf("Fila vazia\n");
    } else {
        printf("Inicio da fila: %d\n", fila -> inicio -> valor);
    }
}

void final(Tfila* fila) {
    if (fila -> qtdElementos == 0) {
        printf("Fila vazia\n");
    } else {
        printf("Final da fila: %d\n", fila -> final -> valor);
    }
}

int remove(Tfila* fila) {
    if (fila -> qtdElementos == 0) {
        return 0; // Indica que a fila está vazia
    }

    No* aux = fila -> inicio; // Cria um ponteiro auxiliar que aponta para o início da fila

    while (aux != NULL) { // Quero remover todos os elementos da fila, por isso é necessário percorrer todos os elementos e agir enquanto 'aux' não for NULL
        fila -> inicio = aux -> prox; // Cria um ponteiro que aponta para o próximo elemento da fila
        free(aux); // Libera a memória alocada para o nó que foi removido da fila
        aux = fila -> inicio; // Atualiza o ponteiro auxiliar para o próximo elemento da fila
    }

    fila -> qtdElementos = 0; // Atualiza o contador de elementos na fila

    return 1;
}

int filaVazia(Tfila* fila) {
    return fila -> qtdElementos == 0;
}

int tamanhoFila(Tfila* fila) {
    return fila -> qtdElementos;
}

