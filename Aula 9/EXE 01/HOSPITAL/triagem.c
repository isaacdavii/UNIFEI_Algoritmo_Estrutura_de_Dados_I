#include <stdio.h>
#include <stdlib.h>
#include "triagem.h"

#define MAX 50

//armazena a quantidade de atendimentos
typedef struct pilha { 
    int qtdAtendimentos;
    TPaciente *topo;
} TPilha;

//armazena o tamanho da fila
typedef struct fila { 
    int tamanho;
    TPaciente *inicio;
    TPaciente *final;
} TFila;

//armazena o nome e prioridade do paciente
typedef struct no { 
    char nome[MAX];
    int prioridade;
    TPaciente *prox;
} TPaciente;

//Cria e retorna uma fila
TFila *criaFila() { 
    TFila *fila = (TFila *) malloc(sizeof(TFila));
    if (!fila) return 0;

    fila -> tamanho = 0;
    fila -> inicio = NULL;
    fila -> final = NULL;

    return fila;
}

//Cria e retorna a pilha de histórico de atendimento
TPilha *criaPilha() { 
    TPilha *pilha = (TPilha *) malloc(sizeof(TPilha));
    if (!pilha) return 0;

    pilha -> qtdAtendimentos = 0;
    pilha -> topo = NULL;

    return pilha;
}

//Insere um paciente da pilha
void push(TPilha *pilha, TPaciente *paciente) { 
    if (!pilha) return;

    TPaciente *novoPaciente = (TPaciente *) malloc(sizeof(TPaciente));
    if (!novoPaciente) return;

    novoPaciente -> prioridade = paciente -> prioridade;
    strcpy(novoPaciente -> nome, paciente -> nome);
    novoPaciente -> prox = pilha -> topo;
    pilha -> topo = novoPaciente;
    pilha -> qtdAtendimentos++;
}

//Remove um paciente da pilha
int pop(TPilha *pilha) { 
    if (!pilha || !pilha -> topo) return 0;

    TPaciente *aux = pilha -> topo;
    pilha -> topo = pilha -> topo -> prox;
    free(aux);
    pilha -> qtdAtendimentos--;
}

//Aloca um novo nó TPaciente, inicializa e o retorna
TPaciente *criaPaciente(char *nome, int prioridade) { 
    TPaciente *novoPaciente = (TPaciente *) malloc(sizeof(TPaciente));
    if (!novoPaciente) return NULL;

    novoPaciente -> prioridade = prioridade;
    strcpy(novoPaciente -> nome, nome);
    novoPaciente -> prox = NULL;

    return novoPaciente;
}

//Insere um paciente na sua fila de prioridade adequada
void adicionarPaciente(TPaciente *novoPaciente, TFila *fila) { 
    if (!fila || !novoPaciente) return;

    if (!fila -> inicio) {
        fila -> inicio = novoPaciente;
        fila -> final = novoPaciente;
    } else {
        TPaciente *aux = fila -> inicio;
        TPaciente *ant = NULL;

        while (aux && novoPaciente -> prioridade <= aux -> prioridade) {
            ant = aux;
            aux = aux -> prox;
        }

        if (!ant) {
            novoPaciente -> prox = fila -> inicio;
            fila -> inicio = novoPaciente;
        } else {
            ant -> prox = novoPaciente;
            novoPaciente -> prox = aux;
        }

        if (!aux) {
            fila -> final = novoPaciente;
        }
    }

    fila -> tamanho++;
}

//Remove o paciente da fila e o insere na pilha
int atenderPaciente(TFila *fila, TPilha *pilha) {
    if (!fila || !fila -> inicio) return 0;

    TPaciente *aux = fila -> inicio;
    fila -> inicio = fila -> inicio -> prox;
    push(pilha, aux);
    fila -> tamanho--;

    return 1;
}

//Verifica qual fila será atendida seguindo as regras estabelecidas
//Chama a função de atender paciente
void GerenciaAtendimento(TFila *U_Alta, TFila *U_Media, TFila *U_Baixa, TPilha *pilha) {
    if (!U_Alta || !U_Media || !U_Baixa || !pilha) return;

    if (U_Alta -> tamanho > 0) {
        atenderPaciente(U_Alta, pilha);
    } else if (U_Media -> tamanho > 0) {
        atenderPaciente(U_Media, pilha);
    } else if (U_Baixa -> tamanho > 0) {
        atenderPaciente(U_Baixa, pilha);
    }
}

//Exibe na tela os dados do último paciente atendido
//printf("ULTIMO ATENDIMENTO\n");
//printf("Paciente : %s\n", ?);
//printf("Prioridade de Atendimento: %d\n", ?);
void mostraUltimoAtendimento(TPilha* pilha) {
    if (!pilha || !pilha -> topo) return;

    printf("ULTIMO ATENDIMENTO\n");
    printf("Paciente : %s\n", pilha -> topo -> nome);
    printf("Prioridade de Atendimento: %d\n", pilha -> topo -> prioridade);
}

//Retorna o tamanho da fila
int tamanhoFila(TFila *fila) {
    if (!fila) return 0;

    return fila -> tamanho;
}

//Retorna o total de atendimentos até o momento
int totalAtendimentos(TPilha *pilha) {
    if (!pilha) return 0;

    return pilha -> qtdAtendimentos;
}

//Esvazia a pilha de atendimento
//Chama a função pop
void reiniciaPilha(TPilha *pilha) {
    if (!pilha) return;

    while (pilha -> topo) {
        pop(pilha);
    }
}

//Abre o arquivo. Para cada linha do arquivo, chama a função criaPaciente
//Verifica a priopridade do paciente e chama a função adicionarPaciente
//Retorna 1 se o paciente foi inserido na sua fila de prioridade, retorna 0 caso contrário
int processaCarga(char *nomeArquivo, TFila *U_Alta, TFila *U_Media, TFila *U_Baixa) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return 0;

    char nome[MAX];
    int prioridade;

    while (fscanf(arquivo, "%s %d", nome, &prioridade) != EOF) {
        TPaciente *novoPaciente = criaPaciente(nome, prioridade);
        if (!novoPaciente) return 0;

        if (prioridade == 1) {
            adicionarPaciente(novoPaciente, U_Alta);
        } else if (prioridade == 2) {
            adicionarPaciente(novoPaciente, U_Media);
        } else if (prioridade == 3) {
            adicionarPaciente(novoPaciente, U_Baixa);
        } else {
            return 0;
        }
    }

    fclose(arquivo);
    return 1;
}

//Esvazia e desaloca pilha
void desalocaPilha(TPilha *pilha) {
    if (!pilha) return;

    while (pilha -> topo) {
        pop(pilha);
    }

    free(pilha);
}

//Esvazia e desaloca fila
void desalocaFila(TFila *fila) {
    if (!fila) return;

    while (fila -> inicio) {
        TPaciente *aux = fila -> inicio;
        fila -> inicio = fila -> inicio -> prox;
        free(aux);
    }

    free(fila);
}
