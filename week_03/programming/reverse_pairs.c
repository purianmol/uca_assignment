#include <stdio.h>
#include <stdlib.h>

long long merge(int* nums, int left, int mid, int right) {
    long long count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    int* temp = (int*)malloc((right - left + 1) * sizeof(int));
    int i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (int p = 0; p < k; p++) {
        nums[left + p] = temp[p];
    }

    free(temp);
    return count;
}

long long mergeSort(int* nums, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    long long count = mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);
    return count;
}

int main() {
    int capacity = 100005;
    int* nums = (int*)malloc(capacity * sizeof(int));
    int n = 0;
    
    while (scanf("%d", &nums[n]) == 1) {
        n++;
    }
    
    if (n > 0) {
        long long result = mergeSort(nums, 0, n - 1);
        printf("%lld\n", result);
    } else {
        printf("0\n");
    }
    
    free(nums);
    return 0;
}
