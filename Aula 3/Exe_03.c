#include <stdio.h>
#include <stdlib.h>

// Ponteiro Simples (*)
// Um ponteiro simples, como int *p, armazena o endereço de uma variável do tipo int. Por exemplo:
// int x = 10;
// int *p = &x;

// Ponteiro Duplo (**)
// Um ponteiro duplo, como int **pp, armazena o endereço de um ponteiro que, por sua vez, aponta para um int. 
// Ele é útil para manipular arrays de ponteiros ou quando precisamos modificar o ponteiro dentro de uma função:

// Ponteiro Triplo (***)
// Um ponteiro triplo, como int ***ppp, armazena o endereço de um ponteiro duplo (int **).
// Ele é usado em situações mais complexas, como na alocação dinâmica de matrizes 2D (array de arrays).
// int **p = malloc(linhas * sizeof(int *));
// int ***ppp = &p;


void alocaMatriz(int ***matriz, int linhas, int colunas) {
// ***matriz - um ponteiro para um ponteiro de ponteiro que permite modificar o ponteiro original. Linha 96,97,98 que é &A, &B, &C
// Primeiro, aloca memória para um array de ponteiros. Depois, para cada linha, aloca memória para um array de inteiros.

    *matriz = (int **) malloc(linhas * sizeof(int *)); 
// linhas * sizeof(int *): A função malloc está alocando memória suficiente para armazenar um array de ponteiros, onde cada ponteiro representa uma linha da matriz.
// Nesta função, estamos alocando espaço para um array de ponteiros, onde cada ponteiro representa uma linha da matriz.

    for (int i = 0; i < linhas; i++) {
        (*matriz)[i] = (int *) malloc(colunas * sizeof(int));
    }
}

void liberaMatriz(int **matriz, int linhas) {
// **matriz - Um ponteiro para a matriz que será liberada.
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
// Para cada linha, libera a memória alocada para as colunas.
    }
    free(matriz);
// Libera a memória alocada para os ponteiros das linhas
}

void inicializaMatriz(int **matriz, int linhas, int colunas) {
// Itera sobre todas as posições da matriz, pedindo ao usuário para inserir um valor em cada posição.
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicaMatrizes(int **A, int **B, int **C, int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
                // i=0 j=0 k=0,1,2
                // i=0 j=1 k=0,1,2
            }
        }
    }
}

int main() {
    int **A, **B, **C;
    int linhasA, colunasA, linhasB, colunasB;

    // MATRIZ A
    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &colunasA);

    // MATRIZ B
    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &colunasB);

    if (colunasA != linhasB) {
        printf("Nao e possivel multiplicar as matrizes\n");
        return 1;
    }

    alocaMatriz(&A, linhasA, colunasA);
    alocaMatriz(&B, linhasB, colunasB);
    alocaMatriz(&C, linhasA, colunasB);

    printf("Inicializando matriz A:\n");
    inicializaMatriz(A, linhasA, colunasA);

    printf("Inicializando matriz B:\n");
    inicializaMatriz(B, linhasB, colunasB);

    multiplicaMatrizes(A, B, C, linhasA, colunasA, colunasB);

    printf("Resultado da multiplicacao (Matriz C):\n");
    imprimeMatriz(C, linhasA, colunasB);

    liberaMatriz(A, linhasA);
    liberaMatriz(B, linhasB);
    liberaMatriz(C, linhasA);

    return 0;
}