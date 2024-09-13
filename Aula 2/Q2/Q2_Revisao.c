#include <stdio.h>
#include <stdlib.h>

#define qtd 50

typedef struct{
    int registro;
    char sexo;
    float altura;
    int idade;
    char corOlhos;
} tPessoa;

void lerDados(tPessoa pessoas[]);
void imprimirVetor(tPessoa pessoas[]);
void gerarRelatorio(tPessoa pessoas[]);

int main(){
    tPessoa pessoas[qtd];

    lerDados(pessoas);
    imprimirVetor(pessoas);
    gerarRelatorio(pessoas);

    return 0;
}

void lerDados(tPessoa pessoas[]){
    FILE *arquivo;

    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++){
        fscanf(arquivo, "%d %c %f %d %c", &pessoas[i].registro, &pessoas[i].sexo, &pessoas[i].altura, &pessoas[i].idade, &pessoas[i].corOlhos);
    }

    fclose(arquivo);
}

void imprimirVetor(tPessoa pessoas[]){
    for (int i = 0; i < qtd; i++){
        printf("Pessoa %d:\n", i + 1);
        printf("Registro: %d\n", pessoas[i].registro);
        printf("Sexo: %c\n", pessoas[i].sexo);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Cor dos olhos: %c\n", pessoas[i].corOlhos);
        printf("--------------------\n");
    }
}

void gerarRelatorio(tPessoa pessoas[]){
    int countCastanhosAltura = 0;
    int maiorIdade = 0;
    int countFemininoIdadeAltura = 0;
    int countHomens = 0;
    int countTotal = 0;

    for (int i = 0; i < qtd; i++){
        if (pessoas[i].corOlhos == 'C' && pessoas[i].altura > 1.60){
            countCastanhosAltura++;
        }

        if (pessoas[i].idade > maiorIdade){
            maiorIdade = pessoas[i].idade;
        }

        if ((pessoas[i].sexo == 'F' && pessoas[i].idade >= 20 && pessoas[i].idade <= 45)){
            countFemininoIdadeAltura++;
        }

        if (pessoas[i].sexo == 'M'){
            countHomens++;
        }

        countTotal++;
    }

    float percentualHomens = (float)countHomens / countTotal * 100;

    printf("Relatorio:\n");
    printf("Media de idade das pessoas com olhos castanhos e altura superior a 1,60m: %.2f\n", (float)countCastanhosAltura / countTotal);
    printf("Maior idade entre os habitantes: %d\n", maiorIdade);
    printf("Quantidade de individuos do sexo feminino com idade entre 20 e 45 anos ou que tenham olhos verdes e altura inferior a 1,70m: %d\n", countFemininoIdadeAltura);
    printf("Percentual de homens: %.2f%%\n", percentualHomens);
}


