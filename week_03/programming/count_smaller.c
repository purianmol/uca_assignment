#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Element;

void merge(Element* arr, int left, int mid, int right, int* ans) {
    Element* temp = (Element*)malloc((right - left + 1) * sizeof(Element));
    int i = left;
    int j = mid + 1;
    int k = 0;
    int right_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            ans[arr[i].idx] += right_count;
            temp[k++] = arr[i++];
        } else {
            right_count++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        ans[arr[i].idx] += right_count;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }

    free(temp);
}

void mergeSort(Element* arr, int left, int right, int* ans) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);
        merge(arr, left, mid, right, ans);
    }
}

int main() {
    int capacity = 100005;
    Element* arr = (Element*)malloc(capacity * sizeof(Element));
    int* ans = (int*)calloc(capacity, sizeof(int));
    int n = 0;
    
    while (scanf("%d", &arr[n].val) == 1) {
        arr[n].idx = n;
        n++;
    }
    
    if (n > 0) {
        mergeSort(arr, 0, n - 1, ans);
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    
    free(arr);
    free(ans);
    return 0;
}
