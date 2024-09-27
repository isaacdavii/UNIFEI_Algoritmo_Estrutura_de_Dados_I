#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaXML.h"

#define MAX_TAG_LENGTH 20

struct no {
    char nomeTag[MAX_TAG_LENGTH];
    struct no *proximo;
};

struct pilhaXML {
    struct no *topo;
    int quantidade;
};

pilhaXML *criaPilha() {
    pilhaXML *pilha = (pilhaXML *) malloc(sizeof(pilhaXML));
    if (pilha) {
        pilha -> topo = NULL;
        pilha -> quantidade = 0;
    }
    return pilha;
}

int empilhaTag(pilhaXML *pilha, char *nomeTag) {
    if (!pilha) return 0;
    tag *novoNo = (tag *)malloc(sizeof(tag));
    if (!novoNo) return 0;
    strncpy(novoNo -> nomeTag, nomeTag, MAX_TAG_LENGTH);
    novoNo -> proximo = pilha -> topo;
    pilha -> topo = novoNo;
    pilha -> quantidade++;
    return 1;
}

tag *desempilha(pilhaXML *pilha) {
    if (!pilha || !pilha->topo) return NULL;
    tag *noRemovido = pilha->topo;
    pilha -> topo = noRemovido -> proximo;
    pilha -> quantidade--;
    return noRemovido;
}

int validaXML(char *nomeArquivo, pilhaXML *pilha) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return 0;

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char *inicioTag = strchr(linha, '<');
        char *fimTag = strchr(linha, '>');
        if (inicioTag && fimTag) {
            char nomeTag[MAX_TAG_LENGTH];
            strncpy(nomeTag, inicioTag + 1, fimTag - inicioTag - 1);
            nomeTag[fimTag - inicioTag - 1] = '\0';

            if (nomeTag[0] != '/') {
                if (!empilhaTag(pilha, nomeTag)) {
                    fclose(arquivo);
                    return 0;
                }
            } else {
                tag *noRemovido = desempilha(pilha);
                if (!noRemovido || strcmp(noRemovido -> nomeTag, nomeTag + 1) != 0) {
                    fclose(arquivo);
                    return 0;
                }
                free(noRemovido);
            }
        }
    }

    fclose(arquivo);
    return pilha -> quantidade == 0;
}

void desalocaPilha(pilhaXML *pilha) {
    while (pilha -> topo) {
        tag *noRemovido = desempilha(pilha);
        free(noRemovido);
    }
    free(pilha);
}