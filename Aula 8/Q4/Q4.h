#ifndef Q4_H
#define Q4_H
#define MAX 50

typedef struct no No;
typedef struct fila Fila;

// Cria uma fila que armazena o total de clientes em espera
Fila* criaFila();

// Adiciona um novo cliente à fila
// Retorna 1 caso o cliente seja inserido com sucesso
// Retorna 0 caso contrário
No *adicionarCliente(Fila *f, char nome[], int numPessoas);

// Retira um cliente da fila
// Retorna 1 caso o cliente seja atendido com sucesso
// Retorno 0 caso contrário
int atenderCliente(Fila *f);

// Retorna o tamanho da fila de espera
int TamanhoFila(Fila *f);

// Retorna o nome do cliente que está no início da fila
// Se a fila estiver vazia, retorna NULL
const char *ClienteTopo(Fila *f);

// Retorna o total de clientes no início da fila
// Se a fila estiver vazia, retorna 0
int TotalClientesTopo(Fila *f);

// Desaloca a fila
// Caso haja clientes, os mesmos deverão ser retirados antes da desalocação da fila
void desalocaFila(Fila *f);

#endif // Q4_H

/* 
Funcionalidades:
1. Adicionar um cliente à fila:
o Quando um cliente chega, seu nome e o número de pessoas que o
acompanham são adicionados à fila de espera. O cliente é informado
sobre a quantidade de pessoas a sua frente.

2. Atender um cliente:
o O cliente no início da fila é removido, e seu nome e o número de pessoas
são mostrados para o atendente.

3. Exibir o tamanho da fila de espera:
o O sistema deve exibir quantos clientes estão na fila de espera.
*/