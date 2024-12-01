#include <stdio.h>
#include <math.h>

int binarySearch(int arr[], int left, int right, int target) {
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

int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;

    int range = 1;
    while (range < n && arr[range] <= target)
        range *= 2;

    return binarySearch(arr, range / 2, fmin(range, n - 1), target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = exponentialSearch(arr, n, target);
    if (result != -1)
        printf("Exponential Search: Elemento encontrado no índice %d\n", result);
    else
        printf("Exponential Search: Elemento não encontrado\n");

    return 0;
}
