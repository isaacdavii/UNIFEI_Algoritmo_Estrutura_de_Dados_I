#ifndef FILA_FILA_H
#define FILA_FILA_H

typedef struct no No;
typedef struct fila Tfila;

// Alocar uma struct do tipo Fila
Tfila* criarFila();

// Enfileirar uma struct do tipo Fila
// Retorna 1 se foi possível enfileirar e 0 caso contrário
int enfileirar(Tfila *fila, int valor);

// Desenfileirar uma struct do tipo Fila
// Retira o primeiro valor da fila e retorna esse valor
// Retorna 1 se foi possível desenfileirar e 0 caso contrário
int desenfileirar(Tfila *fila);

// Mostra quem está no início da fila
void inicio(Tfila *fila);

// Mostra quem está no final da fila
void final(Tfila *fila);

// Remove todos os elementos da fila
// Retorna 1 se foi possível remover os elementos e 0 caso contrário
int remove(Tfila *fila);

// Verifica se a fila está vazia
// Retorna 1 se a fila estiver vazia e 0 caso contrário
int filaVazia(Tfila *fila);

// Retorna a quantidade de elementos da fila
int tamanhoFila(Tfila *fila);






#endif //FILA_FILA_H