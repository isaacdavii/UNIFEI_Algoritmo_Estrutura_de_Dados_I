#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

struct produtos {
    int codigo;
    int quantidade;
    float preco;
};

prod *alocaVet(int qtd) {
    return (prod *) malloc(qtd * sizeof(prod));
}

int preencheVet(char *nomeArquivo, int qtd, prod *vet) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        return 2;
    }

    for (int i = 0; i < qtd; i++) {
        if (fscanf(file, "%d;%d;%f", &vet[i].codigo, &vet[i].quantidade, &vet[i].preco) != 3) {
            fclose(file);
            return 2;
        }
    }

    fclose(file);
    return 1;
}

prod *maiorValor(prod *vet, int qtd) {
    if (qtd == 0) return NULL;

    prod *maisCaro = &vet[0];
    for (int i = 1; i < qtd; i++) {
        if (vet[i].preco > maisCaro->preco) {
            maisCaro = &vet[i];
        }
    }
    return maisCaro;
}

int estoque(prod *vet, int qtd, int valor) {
    int count = 0;
    for (int i = 0; i < qtd; i++) {
        if (vet[i].quantidade > valor) {
            count++;
        }
    }
    return count;
}

void imprimeProduto(prod *P) {
    if (P) {
        printf("%d\n", P->codigo);
        printf("%d\n", P->quantidade);
        printf("%.2f\n", P->preco);
    }
}

void desaloca(prod *P) {
    free(P);
}