/* Verificação de Expressão Matemática Balanceada

Você recebeu uma string que contém uma expressão matemática, a qual inclui
parênteses (), colchetes [] e chaves {}. Sua tarefa é escrever um programa que verifique
se todos os símbolos de abertura e fechamento estão balanceados.

Regras:
1. Para cada parêntese de abertura ( deve haver um correspondente parêntese de
fechamento ), e o mesmo vale para colchetes [] e chaves {}.
2. A ordem correta deve ser mantida. Por exemplo, a expressão ( [ ] ) está
balanceada, mas a expressão ( ] ) não está.

Exemplos:
• A expressão [{(2+3)*5} + 3] está balanceada.
• A expressão [(3*2) + {4*5)] está desbalanceada.

Entrada:
• Uma única string representando a expressão matemática (a string pode conter
operadores e números e deve ter tamanho máximo de 30 caracteres).

Saída:
• Retorne "BALANCEADA" se a expressão estiver balanceada.
• Retorne "DESBALANCEADA" se a expressão estiver desbalanceada

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p -> topo = -1; // Indica que a pilha está vazia com topo == -1
}

int estaVazia(Pilha *p) {
    return p -> topo == -1;
}

int estaCheia(Pilha *p) {
    return p -> topo == MAX - 1; // Indica se a pilha está cheia com "MAX - 1"
}

void empilha(Pilha *p, char item) {
    if (!estaCheia(p)) {
        p -> itens[++(p -> topo)] = item;
    }
}

char desempilha(Pilha *p) {
    if (!estaVazia(p)) {
        return p -> itens[(p -> topo)--];
    }
    return '\0'; // Se a pilha estiver vazia, retorna o caractere nulo '\0'
}

char topo(Pilha *p) {
    if (!estaVazia(p)) {
        return p -> itens[p -> topo]; // Retorna o elemento que está no topo, se a pilha não estiver vazia
    }
    return '\0';
}

int ehCorrespondente(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

const char* verificaExpressaoBalanceada(const char *expressao) {
    Pilha pilha;
    inicializa(&pilha);

    for (int i = 0; i < strlen(expressao); i++) {
        char ch = expressao[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            empilha(&pilha, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (estaVazia(&pilha) || !ehCorrespondente(desempilha(&pilha), ch)) {
                return "DESBALANCEADA";
            }
        }
    }

    return estaVazia(&pilha) ? "BALANCEADA" : "DESBALANCEADA";
}

int main() {
    char expressao[MAX + 1];
    
    printf("Digite a expressão matemática: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';  // Remove newline character

    printf("%s\n", verificaExpressaoBalanceada(expressao));

    return 0;
}