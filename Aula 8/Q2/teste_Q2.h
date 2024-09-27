#ifndef TESTE_Q2_H
#define TESTE_Q2_H

typedef struct no no;
typedef struct pilha Tpilha;

Tpilha *criaPilha();

int push(Tpilha *pilha, char valor);

int percorrePilha(Tpilha *pilha);

void desalocaPilha(Tpilha *pilha);

#endif // TESTE_Q2_H