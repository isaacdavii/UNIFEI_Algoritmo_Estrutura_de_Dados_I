#ifndef LISTASIMPLES_H
#define LISTASIMPLES_h

typedef struct lista TLista;
typedef struct no TNo;

//Cria uma lista vazia
TLista *criaLista();

//Insere um elemento na lista
//Retorna 1 se foi possível inserir
//Retorna 0 caso não tenha sido possível alocar novo nó
int insereElementoInicio(TLista *lista, int valor);

int insereElementoFim(TLista *lista, int valor);

//Remove um elemento da lista
//Retorna 1 se foi possível remover
//Retorna 0 caso não tenha sido possível remover
int removeElemento(TLista *lista, int valor);

//Consulta um elemento na lista
//Retorna 1 se o elemento está na lista
//Retorna 0 caso contrário
int consultaElemento(TLista *lista, int valor);

//Esvazia a lista
void esvaziaLista(TLista *lista);

//Retorna 1 se a lista está vazia
//Retorna 0 caso contrário
int listaVazia(TLista *lista);

//Imprime todos os elementos da lista
void imprimeLista(TLista *lista);

//Retorna o tamanho da lista
int tamanhoLista(TLista *lista);

#endif // LISTASIMPLES_H