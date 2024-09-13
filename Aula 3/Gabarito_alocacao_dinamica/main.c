#include <stdio.h>
#include <stdlib.h>

int questao1();
int questao2();
int questao3();
void imprimeMatriz(int **vet, int linhas, int colunas);
void encontraRepetidos(int *vet1, int tam1, int *vet2, int tam2);
void imprimeVetor(int *vet, int tam);

int main() {
    questao3();
    return 0;
}

//***********QUESTÃO 1****************///
int questao1()
{
    //DECLARAÇÃO DE VARIÁVEIS
    int *vet1;
    int *vet2;
    int tamVet1, tamVet2;

    //Primeiro vetor
    printf("Digite a quantidade de elementos do primeiro vetor:");
    scanf("%d", &tamVet1);

    //Alocação dinâmica do primeiro vetor
    vet1 = (int*)malloc(tamVet1*sizeof(int));
    if (!vet1)
    {
        printf("Erro ao alocar memório do primeiro vetor");
        return 1;
    }

    //Preenchimento do primeiro vetor
    for (int i = 0; i < tamVet1; i++)
    {
        printf("\nDigite o %d valor: ", i+1);
        scanf("%d", &vet1[i]);
    }

    //Segundo vetor
    printf("\nDigite a quantidade de elementos do primeiro vetor:");
    scanf("%d", &tamVet2);

    //Alocação dinâmica do segundo vetor
    vet2 = (int*)malloc(tamVet2*sizeof(int));
    if (!vet2)
    {
        printf("Erro ao alocar memório do primeiro vetor");
        return 1;
    }

    //Preenchimento do segundo vetor
    for (int i = 0; i < tamVet2; i++)
    {
        printf("\nDigite o %d valor: ", i+1);
        scanf("%d", &vet2[i]);
    }

    //Chamar a função para verificar elementos iguais
    encontraRepetidos(vet1, tamVet1, vet2, tamVet2);
    free(vet1);
    free(vet2);

}

void encontraRepetidos(int *vet1, int tam1, int *vet2, int tam2)
{
    for (int i = 0; i < tam1; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            if (vet1[i] == vet2[j])
            {
                printf("%d\n", vet1[i]);
            }
        }
    }
}


//***********QUESTÃO 2****************///
int questao2()
{
    //DECLARAÇÃO DE VARIÁVEIS
    int *vet;
    int tamAtual;
    int novoTam;
    int continua = 1;

    //Alocar vetor dinamicamente
    printf("Digite o tamanho inicial do vetor: ");
    scanf("%d", &tamAtual);

    vet = (int*) malloc(tamAtual * sizeof (int));
    if (!vet)
    {
        printf("Erro ao alocar memória");
        return 1;
    }

    //Preencher o vetor
    for (int i =0; i < tamAtual; i++)
        vet[i] = rand()%100;

    imprimeVetor(vet, tamAtual);

    printf("Você deseja alterar o tamanho do vetor? (0 para nao e 1 para sim)");
    scanf("%d", &continua);

    while (continua)
    {
        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &novoTam);
        vet = realloc(vet, novoTam * sizeof(int));
        if (!vet)
        {
            printf("Erro ao alocar memória");
            return 1;
        }
        if (tamAtual < novoTam)
        {
            for (int i = tamAtual; i < novoTam; i++)
                vet[i] = rand()%100;
        }
        imprimeVetor(vet, novoTam);
        printf("Você deseja alterar o tamanho do vetor? (0 para nao e 1 para sim)");
        scanf("%d", &continua);
    }
    free(vet);
    return 0;
}

void imprimeVetor(int *vet, int tam)
{
    for (int i=0; i<tam; i++)
        printf("%d\n", vet[i]);
}


//***********QUESTÃO 3****************///

int questao3()
{
    int l1, l2, lr, c1, c2, cr;
    int **mat1;
    int **mat2;
    int **matRes;

    printf("Digite a quantidade de linhas da primeira matriz: ");
    scanf("%d", &l1);

    printf("Digite a quantidade de colunas da primeira matriz: ");
    scanf("%d", &c1);

    printf("Digite a quantidade de linhas da segunda matriz: ");
    scanf("%d", &l2);

    printf("Digite a quantidade de colunas da segunda matriz: ");
    scanf("%d", &c2);

    //"Para que exista o produto entre a matriz A e a matriz B, é necessário que o número de colunas da primeira matriz,
    // no caso A, seja igual ao número de linhas da segunda matriz, no caso B."

    if (c1 != l2)
    {
        printf("Não é possível realizar o produto entre as matrizes");
        return 1;
    }

    //ALOCAR E PREENCHER A MATRIZ A
    mat1 = (int**) malloc (l1 * sizeof(int*));
    if (!mat1)
    {
        printf("Erro ao alocar memoria\n");
        return 2;
    }
    for (int i = 0; i < l1; i++)
    {
        mat1[i] = (int*) malloc (c1 * sizeof(int));
        if (!mat1[i])
        {
            printf("Erro ao alocar memoria\n");
            return 2;
        }
    }
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Digite o elemento [%d, %d] da matriz A: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    //ALOCAR E PREENCHER A MATRIZ B
    mat2 = (int**) malloc (l2 * sizeof(int*));
    if (!mat2)
    {
        printf("Erro ao alocar memoria\n");
        return 2;
    }
    for (int i = 0; i < l2; i++)
    {
        mat2[i] = (int*) malloc (c2 * sizeof(int));
        if (!mat2[i])
        {
            printf("Erro ao alocar memoria\n");
            return 2;
        }
    }
    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Digite o elemento [%d, %d] da matriz B: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    //REALIZAR O PRODUTO
    //A matriz resultante tem o total de linhas da matriz A e o total de colunas da matriz B
    //ALOCAR E PREENCHER A MATRIZ RESULTANTE
    matRes = (int**) calloc (l1,  sizeof(int*));
    if (!matRes)
    {
        printf("Erro ao alocar memoria\n");
        return 2;
    }
    for (int i = 0; i < l1; i++)
    {
        matRes[i] = (int*) calloc (c2, sizeof(int));
        if (!matRes[i])
        {
            printf("Erro ao alocar memoria\n");
            return 2;
        }
    }

    for (int i = 0; i < l1; i++)
    {
        for (int k = 0; k < c2; k++)
        {
            for (int j = 0; j < l1; j++)
            {
                matRes[i][k] = matRes[i][k] + (mat1[i][j] * mat2[j][k]);
            }
        }
    }

    imprimeMatriz(matRes, l1, c2);

    free(mat1);
    free(mat2);
    free(matRes);

    return 0;
}

void imprimeMatriz(int **mat, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

}