//
// Created by Vanessa on 06/09/2024.
//

#ifndef PILHA_DINAMICA_PILHADINAMICA_H
#define PILHA_DINAMICA_PILHADINAMICA_H

typedef struct pilhaDinamica pDin;
typedef struct no no;

//Cria uma pilha dinâmica de números inteiros
//Armazena a quantidade de elementos na pilha
//Retorna a pilha
pDin *criaPilha();

//Verifica se a pilha está vazia
//Retorna 1 se tiver vazia
//Retorna 0 se não estiver
int pilhaVazia(pDin *pilha);

//Insere o elemento valor na pilha
//Retorna 1 se a inserção aconteceu
//Retorna 0 caso haja erro de alocação
int push(pDin *pilha, int valor);

//Remove o elemento da pilha
//Retorna o elemento removido
//Retorna -1 caso a pilha esteja vazia
int pop(pDin *pilha);

//Imprime na tela o elemento que está no topo da pilha
void topo(pDin *pilha);

//Retorna a quantidade de elementos na pilha
void qtdElementos(pDin *pilha);

//Remove todos os elementos da pilha
void esvazia(pDin *pilha);

//Desaloca a pilha
void desalocaPilha(pDin *pilha);




#endif //PILHA_DINAMICA_PILHADINAMICA_H
