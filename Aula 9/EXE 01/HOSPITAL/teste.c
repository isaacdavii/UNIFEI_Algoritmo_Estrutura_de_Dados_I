typedef struct pilha { //armazena a quantidade de atendimentos
    int qtdAtendimentos;
    TPaciente *topo;
} TPilha;

typedef struct fila { //armazena o tamanho da fila
    int tamanho;
    TPaciente *inicio;
    TPaciente *final;
} TFila;

typedef struct no { //armazena o nome e prioridade do paciente
    char nome[MAX];
    int prioridade;
} TPaciente;