//
// Created by Vanessa on 06/09/2024.
//

#ifndef PILHA_ESTATICA_PILHAEST_H
#define PILHA_ESTATICA_PILHAEST_H

typedef struct pilhaEstatica pEst;

//Cria uma pilha estática de números inteiros
//O tamanho máximo da pilha é informado pelo usuário
//Recebe o tamanho máximo
//Retorna a pilha
pEst *criaPilha(int tamPilha);

//Verifica se a pilha está cheia
//Retorna 1 se tiver cheia
//Retorna 0 se não estiver
int pilhaCheia(pEst *pilha);

//Verifica se a pilha está vazia
//Retorna 1 se tiver vazia
//Retorna 0 se não estiver
int pilhaVazia(pEst *pilha);

//Insere o elemento valor na pilha
//Retorna 1 se a inserção aconteceu
//Retorna 0 caso a pilha esteja cheia
int push(pEst *pilha, int valor);

//Remove o elemento da pilha
//Retorna o elemento removido
//Retorna -1 caso a pilha esteja vazia
int pop(pEst *pilha);

//Imprime na tela o elemento que está no topo da pilha
void topo(pEst *pilha);

//Remove todos os elementos da pilha
void esvazia(pEst *pilha);

//Desaloca a pilha
void desalocaPilha(pEst *pilha);






#endif //PILHA_ESTATICA_PILHAEST_H
