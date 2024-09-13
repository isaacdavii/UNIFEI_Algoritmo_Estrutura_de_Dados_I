#include <stdio.h>
#include "produto.h"

//Essa função lê o arquivo produtos.txt e carrega na matriz
void carregaMatriz(int mat[][3], int linhas, char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");

    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //LER DO ARQUIVO E CARREGAR NA MATRIZ
    for (int l = 0; l < linhas; l++) {
        fscanf(arq, "%d %d %d", &mat[l][0], &mat[l][1], &mat[l][2]);
        if (ferror(arq)) {
            printf("Erro ao ler do arquivo.\n");
            return;
        }
    }
    fclose(arq);
}

//Essa função imprime os dados da matriz, no mesmo formato que está no arquivo
void imprimeMatriz(int mat[][3], int linhas) {
    for (int l=0; l < linhas; l++)
        printf("%d %d %d \n", mat[l][0], mat[l][1], mat[l][2]);
}

//Essa função altera o valor dos produtos
void alteraValor(int mat[][3], int linhas, int desconto) {
    for(int i =0; i < linhas; i++) {
        if (mat[i][2] > 50)
            mat[i][1] = mat[i][1] - desconto;
    }
}