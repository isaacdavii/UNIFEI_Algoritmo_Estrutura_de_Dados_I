#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int **alocaMatriz(int linhas, int colunas) {
    int **mat = (int **) malloc(linhas * sizeof(int *));
    if (!mat) {
        return NULL;
    }
    for (int i = 0; i < linhas; i++) { // Para cada linha, aloca um array de inteiros que representa as colunas da matriz
        mat[i] = (int *) malloc(colunas * sizeof(int));
        if (!mat[i]) { // Se falhar...
            for (int j = 0; j < i; j++) // Descoloca as linhas já alocadas e retorna NULL para evitar vazamento de memória
                free(mat[j]);
            free(mat);
            return NULL;
        }
    }

    return mat; // Retorna o ponteiro para a matriz alocada
}

/*void preencheMatriz(int **mat, int linhas, int colunas, int opcao) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            switch (opcao) {
                case 1:
                    mat[i][j] = (3 * i) + (4 * j); // 0 4 3 7 (2º depois essa)
                    break;                         // A + B = C = 0 1 -1 0 (3º somando à mão fica assim)
                case 2:
                    mat[i][j] = (-4 * i) + (-3 * j); // 0 -3 -4 -7 (1º escolheu essa)
                    break;
                case 3:
                    mat[i][j] = 0;
                    break;
            }
        }
    }
}*/
void preencheMatriz(int **mat, int linhas, int colunas, int opcao) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (opcao == 1) {
                mat[i][j] = 3 * i + 4 * j;
            } else if (opcao == 2) {
                mat[i][j] = -4 * i - 3 * j;
            } else if (opcao == 3) {
                mat[i][j] = 0;
            }
        }
    }
}

int **somaMatriz(int **matA, int **matB, int lin, int col) {
    int **matSoma = alocaMatriz(lin, col);
    if (!matSoma) {
        return NULL;
    }
    for (int i = 0; i < lin; i++) { // Para cada elemento, a função soma os elementos corresponedentes
        for (int j = 0; j < col; j++) {
            matSoma[i][j] = matA[i][j] + matB[i][j];
        }
    }
    return matSoma;
}

void imprimeMatriz(int **mat, int linhas, int colunas) { // Imprime a matriz
    for (int i = 0; i < linhas; i++) { // Percorre cada linha da matriz
        for (int j = 0; j < colunas; j++) { // Percorre cada coluna da matriz
            printf("%d\t", mat[i][j]); // Imprime cada elemento
        }
        printf("\n"); // Muda de linha após imprimir todos os elementos de uma linha da matriz
    }
}

void desalocaMatriz(int **M) { // Desaloca a memória da matriz. 
    free(M); // Libera o array de ponteiros
}


