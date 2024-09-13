#include <stdio.h>
#include <stdlib.h>

// Função de alocar, liberar, inicializar e imprimir 

void alocaMatriz(int ***matriz, int linhas, int colunas) {
    *matriz = (int **) malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        *matriz[i] = (int *) malloc(linhas * sizeof(int));
    }
}



void liberaMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
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
}