#include "pilhaEst.h"
#include <stdlib.h>
#include <stdio.h>

struct pilhaEstatica {
    int tamanho;
    int topo;
    int *vet;
};

// Para criar uma pilha estática, é necessário:
// Passo 1 - Aloca a struct
// Passo 2 - Aloca o vetor
// Passo 3 - Inicializa tamanho e topo
// Passo 4 - Retorna a pilha

pEst *criaPilha(int tamPilha) { // Cria pilha com tam específico
    pEst *pilha = (pEst *) malloc(sizeof(pEst)); // Aloca memória para a estrutura da pilha
    
    pilha -> tamanho = tamPilha; // Define o tamanho da pilha
    pilha -> topo = -1; // Inicializa o topo da pilha como -1, indicando que a pilha está vazia
    
    pilha -> vet = (int *) malloc(tamPilha * sizeof(int)); // Aloca memória para o vetor que armazenará os elementos da pilha
    if(!pilha)
        return NULL;
    
    return pilha; // Retorna o ponteiro para a pilha criada
}

int pilhaCheia(pEst *pilha) { // Verifica se a pilha está cheia
    return pilha -> topo == pilha -> tamanho - 1; // Verifica se o topo da pilha é igual ao tamanho da pilha - 1
}

int pilhaVazia(pEst *pilha) { // Verifica se a pilha está vazia
    return pilha -> topo == -1; // Verifica se o topo da pilha é igual a -1
}

int push(pEst *pilha, int valor) { // Insere um novo valor no topo da pilha
    if (pilhaCheia(pilha)) { // Verifica se a pilha está cheia
        return 0;
    }

    pilha -> topo++; // Incrementa o topo da pilha, movendo-o para a próxima posição
    pilha -> vet[pilha -> topo] = valor; // Armazena o valor fornecido na nova posição do topo

    return 1;
}

int pop(pEst *pilha) { // Remove e retorna o valor no topo da pilha
    if (pilhaVazia(pilha)) {
        return -1;
    }

    int valor = pilha -> vet[pilha -> topo]; // Armazena o valor do topo
    pilha -> topo--; // Decrementa o topo, removendo o elemento da pilha

    return valor; // Retorna o valor que foi removido
}

void topo(pEst *pilha) { // Exibe o valor no topo da pilha sem removê-lo
    if (pilhaVazia(pilha)) { // Verifica se a pilha está vazia
        printf("Pilha vazia\n");
    } else { // Se não estiver, imprime o valor que está no topo
        printf("Topo: %d\n", pilha -> vet[pilha -> topo]);
    }
}

void esvazia(pEst *pilha) { // Esvazia a pilha
    pilha -> topo = -1; // Define o topo da pilha como -1, indicando que todos itens foram removidos
}

void desalocaPilha(pEst *pilha) { // Libera a memória alocada para a pilha
    free(pilha -> vet); // Libera a memória alocada para o vetor de elementos da pilha
    free(pilha); // Libera a memória alocada para a struct da pilha
}