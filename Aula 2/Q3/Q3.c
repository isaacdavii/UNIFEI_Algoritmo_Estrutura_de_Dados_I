#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerDados(const char *nomeArquivo, float numeros[], int *tamanho);
void contarNumeros(float numeros[], int tamanho);

int main() {
    const char *arquivo = "dados.txt";
    float numeros[20];
    int tamanho;

    printf("Tentando abrir o arquivo: %s\n", arquivo);
    lerDados(arquivo, numeros, &tamanho);

    if (tamanho > 0) {
        printf("Dados lidos com sucesso. Tamanho: %d\n", tamanho);
        contarNumeros(numeros, tamanho);
    } else {
        printf("Nenhum dado foi lido.\n");
    }

    return 0;
}

void lerDados(const char *nomeArquivo, float numeros[], int *tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    char linha[256];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        perror("Erro");
        return;
    }

    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        int i = 0;
        while (token != NULL && i < 20) {
            numeros[i] = atof(token);
            token = strtok(NULL, ",");
            i++;
        }
        *tamanho = i;
    } else {
        *tamanho = 0;
    }

    fclose(arquivo);
}

void contarNumeros(float numeros[], int tamanho) {
    int ocorrencias[20] = {0};
    int jaContado[20] = {0}; // Array auxiliar para marcar números já contados

    for (int i = 0; i < tamanho; i++) {
        if (jaContado[i] == 0) { // Verifica se o número já foi contado
            for (int j = 0; j < tamanho; j++) {
                if (numeros[i] == numeros[j]) {
                    ocorrencias[i]++;
                    jaContado[j] = 1; // Marca todos os índices duplicados como contados
                }
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (ocorrencias[i] > 1) { // Consider only numbers that occur more than once
            printf("%.2f ocorre %d vez(es)\n", numeros[i], ocorrencias[i]);
        }
    }
}