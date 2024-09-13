#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct vetor{
    int tam;
    int *vet;
};

vet *cria(int tam) {
    vet *vetTAD;

    vetTAD = (vet *) malloc(sizeof(vet*));
    if(!vetTAD) {
        return NULL;
    }

    vetTAD -> tam = tam;

    vetTAD -> vet = (int *) malloc(tam * sizeof(int));
    if(vetTAD -> vet) {
        return NULL;
    }

    return vetTAD;
}

void libera(vet *vet) {
    free(vet);
}

int getTam(vet *vet) {
    return vet -> tam;
}

int acessa(vet *vetTAD, int pos) {
    if(pos < 0 || pos >= vetTAD -> tam) {
        return -1;
    }

    return vetTAD -> vet[pos];
}

void preencheAleatoriamente( vet *vetTAD) {
    int i;
    for(i = 0; i < vetTAD -> tam; i++) {
        vetTAD -> vet[i] = rand() % 100;
    }
}
