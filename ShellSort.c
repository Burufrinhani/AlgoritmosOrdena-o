#include <stdio.h>
#include <math.h>
#define N 8
                
void shell(int *lista, int tamanho);
int lista[N] = {1, 9, 6, 35, 2, 99, 8, 7};
                
void main() {
    for (int w = 0; w < N; w++) {
        printf("%d ", lista[w]);
    }
    printf("\n");
    shell(lista, N);
    for (int w = 0; w < N; w++) {
        printf("%d ", lista[w]);
    }
    printf("\n");
}
                
void shell(int *lista, int tamanho) {
    int i, j, aux;
    float k = log(tamanho + 1) / log(3);
    k = floor(k + 0.5);
    int h = (pow(3, (int)k) - 1) / 2;
    while (h > 0) {
        for (i = h; i < tamanho; i++) {
            aux = lista[i];
            j = i;
            while (j >= h && lista[j - h] > aux) {
                lista[j] = lista[j - h];
                j -= h;
            }
            lista[j] = aux;
            }
            h = (h - 1) / 3;
    }
}