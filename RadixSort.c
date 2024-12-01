int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


void countingSortAsc(int array[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void countingSortDesc(int array[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    for (int i = 8; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void radixSortAsc(int array[], int n) {
    int maxElement = getMax(array, n);

    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSortAsc(array, n, place);
    }
}

void radixSortDesc(int array[], int n) {
    int maxElement = getMax(array, n);

    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSortDesc(array, n, place);
    }
}

int main() {
    int data[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(data) / sizeof(data[0]);

    // Crescente
    printf("Array ordenado em ordem crescente:\n");
    radixSortAsc(data, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int dataDesc[] = {121, 432, 564, 23, 1, 45, 788};

    // Decrescente
    printf("Array ordenado em ordem decrescente:\n");
    radixSortDesc(dataDesc, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", dataDesc[i]);
    }
    printf("\n");

    return 0;
}