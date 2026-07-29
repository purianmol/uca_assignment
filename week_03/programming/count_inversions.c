#include <stdio.h>
#include <stdlib.h>

long long merge(int* arr, int left, int mid, int right) {
    long long count = 0;
    int* temp = (int*)malloc((right - left + 1) * sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }

    free(temp);
    return count;
}

long long mergeSort(int* arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

int main() {
    int capacity = 100005;
    int* arr = (int*)malloc(capacity * sizeof(int));
    int n = 0;
    
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }
    
    if (n > 0) {
        long long result = mergeSort(arr, 0, n - 1);
        printf("%lld\n", result);
    } else {
        printf("0\n");
    }
    
    free(arr);
    return 0;
}
