#ifndef TADVET_TAD_H
#define TADVET_TAD_H

typedef struct vetor vet;

//Função cria - Aloca e retorna vetor de tamanho tam
vet * cria(int tam);

//Função libera - Libera a memória do vetor
void libera(int *vet);

//Função acessa - Retorna o valor do elemento[i]
int acessa(vet *vetTAD, int pos);

//Função atribui - Atribui valor ao elemento [i]
void atribui(vet vetTAD);

//Função tamanho - Retorna a qtd de elementos do vetor
int tamanho(vet vetTAD);

//Função redimensionar – Redimensiona o tamanho do vetor
int redimensionar(vet vetTAD);

//Função preencheAleatoriamente – Preenche o vetor aleatoriamente
int preencheAleatoriamente(vet *vetTAD);

//Função imprime – Imprime o vetor com tamanho tam
int imprime(vet vetTAD);


#endif //TADVET_TAD_H