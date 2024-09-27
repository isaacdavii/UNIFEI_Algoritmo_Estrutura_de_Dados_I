#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

struct lista {
    TNo *inicio;
    int qtdElementos;
};

struct no {
    int valor;
    TNo *prox;
};

//Cria uma lista vazia
TLista *criaLista() {
    TLista *lista = (TLista *) malloc(sizeof(TLista));]
    if (!lista) return NULL;

    lista -> qtdElementos = 0;
    lista -> inicio = NULL;

    return lista;
}

//Insere um elemento na lista
//Retorna 1 se foi possível inserir
//Retorna 0 caso não tenha sido possível alocar novo nó
int insereElementoInicio(TLista *lista, int valor) {
    TNo *novoNo = (TNo *) malloc(sizeof(TNo));
    if (!novoNo) return 0;

    if(!lista -> inicio) return 0;

    novoNo -> valor = valor;
    novoNo -> prox = lista -> inicio;
    lista -> inicio = novoNo;

    lista -> qtdElementos++;

    return 1;
}

int insereElementoFim(Tlista *lista, int valor) {
    TNo *novoNo = (TNo *) malloc(sizeof(TNo));
    if (!novoNo) return -1;

    TNo *aux = lista -> inicio;
    while (aux -> prox != NULL) {
        aux = aux -> prox;
    }

    aux -> prox = novoNo;
    novoNo -> valor = valor;
    novoNo -> prox = NULL;

    lista -> qtdElementos++;

    return 1;
}

//Remove um elemento da lista
//Retorna 1 se foi possível remover
//Retorna 0 caso não tenha sido possível remover
int removeElemento(TLista *lista, int valor) {
    if (!lista -> inicio) return 0;

    TNo *aux = lista -> inicio;
    TNo *noRemovido;
    if (!aux) return 0;
    
    //Verificar se o elemento buscado é o primeiro da lista
    if (aux -> valor == valor) {
        lista -> inicio = aux -> prox;
        free(aux);
        lista -> qtdElementos--;

        return 1;
    }

    //Procurar o elemento buscado na lista
    while (aux -> prox != NULL && aux -> prox -> valor != valor) {
        aux = aux -> prox;
    }
    if (!aux -> prox) return 0; //Elemento não encontrado

    noRemovido = aux -> prox;
    aux -> prox = aux -> prox -> prox;
    free(noRemovido);
    lista -> qtdElementos--;

    return 1;
}

//Consulta um elemento na lista
//Retorna 1 se o elemento está na lista
//Retorna 0 caso contrário
int consultaElemento(TLista *lista, int valor);

//Esvazia a lista
void esvaziaLista(TLista *lista) {
    if (!lista -> inicio) return;

    TNo *aux = lista -> inicio;
    TNo *noRemovido;

    while (aux) {
        noRemovido = aux;
        aux = aux -> prox;
        free(noRemovido);
    }

    lista -> qtdElementos = 0;

    return;
}

//Retorna 1 se a lista está vazia
//Retorna 0 caso contrário
int listaVazia(TLista *lista);

//Imprime todos os elementos da lista
void imprimeLista(TLista *lista);

//Retorna o tamanho da lista
int tamanhoLista(TLista *lista);

#endif // LISTASIMPLES_H