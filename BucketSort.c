#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para realizar o Bucket Sort
void bucketSort(float arr[], int n) {
    // Criar baldes
    float **buckets = (float **)malloc(BUCKET_SIZE * sizeof(float *));
    int *bucketSizes = (int *)malloc(BUCKET_SIZE * sizeof(int));

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribuir os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_SIZE); // Calcular o índice do balde
        if (bucketIndex >= BUCKET_SIZE) {
            bucketIndex = BUCKET_SIZE - 1; // Garantir que o índice não exceda o tamanho do balde
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Adicionar o elemento ao balde
    }

    // Ordenar cada balde e concatenar os resultados
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]); // Ordenar o balde
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j]; // Concatenar os elementos ordenados
            }
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite a quantidade de números que você deseja ordenar: ");
    scanf("%d", &n);

    // Alocar memória para o array
    float *arr = (float *)malloc(n * sizeof(float));

    // Ler os números do usuário
    printf("Digite os números (no intervalo [0, 1)): \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Array original: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array ordenado: ");
    printArray(arr, n);

    free(arr);

    return 0;
}