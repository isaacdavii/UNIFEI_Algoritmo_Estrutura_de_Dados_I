#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q4.h"

int main() {
    Fila *f = criaFila();

    adicionarCliente(f, "Joao", 3);
    adicionarCliente(f, "Maria", 2);
    adicionarCliente(f, "Jesus", 1);
    adicionarCliente(f, "Paulo", 2);
    adicionarCliente(f, "Pedro", 4);

    atenderCliente(f);
    atenderCliente(f);
    atenderCliente(f);

    adicionarCliente(f, "Lucas", 3);

    printf("Tamanho da fila: %d\n", TamanhoFila(f));

    printf("Cliente no topo: %s\n", ClienteTopo(f));

    printf("Total de clientes no topo: %d\n", TotalClientesTopo(f));

    desalocaFila(f);
}