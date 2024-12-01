#include <stdio.h>
#include <math.h>

// Implementação do Jump Search
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n); // Tamanho ideal do salto
    int prev = 0;

    // Pula blocos até encontrar um maior ou igual ao alvo
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Busca linear dentro do bloco
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// Implementação do Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Função principal para teste
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    // Testando Jump Search
    int resultJump = jumpSearch(arr, n, target);
    if (resultJump != -1)
        printf("Jump Search: Elemento encontrado no índice %d\n", resultJump);
}