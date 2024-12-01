#include <stdio.h>
#include <stdlib.h>

int buscaInterpolada(int *arr, int chave, int inicio, int fim) {
    if (inicio <= fim && chave >= arr[inicio] && chave <= arr[fim]) {
        int meio = inicio + ((chave - arr[inicio]) * (fim - inicio) / (arr[fim] - arr[inicio]));

        if (arr[meio] == chave)
            return meio;

        if (arr[meio] > chave)
            return buscaInterpolada(arr, chave, inicio, meio - 1);
        
        return buscaInterpolada(arr, chave, meio + 1, fim);
    }
    return -1;
}

int main() {
    int arr[10] = {13, 14, 16, 20, 47, 69, 75, 80, 85, 90};
    int valor, op;

    do {
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &valor);
        int resultado = buscaInterpolada(arr, valor, 0, 9);
        if (resultado != -1) {
            printf("\nResultado: %d encontrado na posição %d\n", valor, resultado);
        } else {
            printf("\nResultado: %d não encontrado\n", valor);
        }

        printf("\n0 - Sair\n1 - Nova busca\n");
        scanf("%d", &op);
    } while (op != 0);

    return 0;
}
