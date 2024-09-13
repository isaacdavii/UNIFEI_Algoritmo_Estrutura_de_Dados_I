#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main(){

    int tam;
    int res;
    vet *vetTAD;

    printf("Qual o tamanho do vetor? ");
    scaf("%d", &tam);

    vetTAD = cria(tam);
    if (!vetTAD) {
        printf("Erro ao alocar memória\n");
        return 1; // return 1 means that the program had an error
    }

    preencheAleatoriamente(vetTAD);

    res = acessa(vetTAD, 2);
    printf("\n%d", res);

    libera(vetTAD);

    printf("%d", getTam(vetTAD));
}