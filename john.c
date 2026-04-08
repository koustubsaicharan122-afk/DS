#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n, i;

    scanf("%d", &n);

    int john[50], mary[50], merged[100];

    for (i = 0; i < n; i++) {
        scanf("%d", &john[i]);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &mary[i]);
    }

    for (i = 0; i < n; i++) {
        merged[i] = john[i];
        merged[n + i] = mary[n - 1 - i];
    }

    mergeSort(merged, 0, 2*n - 1);

    for (i = 0; i < 2*n; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}