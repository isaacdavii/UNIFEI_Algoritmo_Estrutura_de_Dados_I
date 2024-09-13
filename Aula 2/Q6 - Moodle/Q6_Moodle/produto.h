#ifndef INC_1_PRODUTOS_PRODUTO_H
#define INC_1_PRODUTOS_PRODUTO_H
#define col 3

// O meu 'produto.h' é minha interface de comunicação com o usuário.

//Essa função lê o arquivo produtos.txt e carrega na matriz
void carregaMatriz(int mat[][col], int linhas, char *nomeArquivo);

//Essa função imprime os dados da matriz, no mesmo formato que está no arquivo
void imprimeMatriz(int mat[][col], int linhas);

//Essa função altera o valor dos produtos
void alteraValor(int mat[][col], int linhas, int desconto);

#endif //INC_1_PRODUTOS_PRODUTO_H
