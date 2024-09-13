#include <stdio.h>

void mm(int v[], int n, int *min, int *max) {
    // v[]: Um array de inteiros.
    // n: Tamanho do array.
    *min = v[0]; // Inicializa os valores de min e max com o primeiro elemento do array.
    *max = v[0];
    
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) {
            *min = v[i];
        }
        
        if (v[i] > *max) {
            *max = v[i];
        }
    }
}

int main() {
    int v[] = {5, 2, 8, 1, 7};
    int n = sizeof(v) / sizeof(v[0]); // Calcula o número de elementos no array v.
    // O array v contém 5 elementos.
    // sizeof(v): Em um sistema onde 'int' tem 4 bytes, o resultado será 5 * 4 = 20 bytes.
    // sizeof(v[0]): O tamanho de um 'int' é 4 bytes.
    int min, max;
    
    mm(v, n, &min, &max); // Chama a função mm, passando o array, o tamanho do array, e os endereços de min e max.
    
    printf("O menor elemento do vetor e: %d\n", min);
    printf("O maior elemento do vetor e: %d\n", max);
    
    return 0;
}