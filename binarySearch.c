#include <stdio.h>

int buscaBinaria(int lista[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (lista[meio] == valor) {
            return meio;
        } else if (lista[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int listaOrdenada[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(listaOrdenada) / sizeof(listaOrdenada[0]);
    int valorDesejado = 2;
    int indice = buscaBinaria(listaOrdenada, tamanho, valorDesejado);

    if (indice != -1) {
        printf("Valor %d encontrado no indice %d\n", valorDesejado, indice);
    } else {
        printf("Valor nao encontrado na lista.\n");
    }

    return 0;
}