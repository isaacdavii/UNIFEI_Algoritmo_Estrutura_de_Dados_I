#include <stdio.h>
#include <stdlib.h>
#include "vetDin.h"

int *alocaVetor(int tam) {
    int *vet = (int *) malloc(tam * sizeof(int)); // Aloca o vetor de tamanho 'tam'
    if (!vet) {
        return NULL; // Indica falha na alocação da memória
    }
    return vet;
}

int preencheVetor(char *nomeArquivo, int tam, int *vet) { // Preenche o vetor com os valores do arquivo
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq)
        return -1; // Se der problema o arquivo não foi aberto
    for (int i = 0; i < tam; i++) {
        if (fscanf(arq, "%d", &vet[i]) != 1) {
            fclose(arq);
            return -2; // Se der problema na leitura do arquivo
        }
    }
    fclose(arq);
    return 1;
}

int econtraValor(int *vet, int tam, int valor) { // Retorna a posição do valor no vetor
    for (int i = 0; i < tam; i++) {
        if (vet[i] == valor)
            return i; // Retorna a posição do valor no vetor
    }
    return -1;
}

// Prof, se a Sra estiver lendo isso, já tentei alterar cada linha do código porém ele não quer funcionar no segundo caso de teste fornecido no Moodle!
// Ele está dando erro na leitura do arquivo (return -2).
