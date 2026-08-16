
#include <stdio.h>

int findFourTimesRepeating(int arr[], int n) {
    int result = 0;
    
    for (int i = 0; i < 32; i++) {
        int bit_sum = 0;
        int bit_mask = (1 << i);
        
        for (int j = 0; j < n; j++) {
            if (arr[j] & bit_mask) {
                bit_sum++;
            }
        }
        
        if (bit_sum % 3 != 0) {
            result |= bit_mask;
        }
    }
    
    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Expected output: 3\n");
    printf("Actual output: %d\n", findFourTimesRepeating(arr, n));
    
    return 0;
}
