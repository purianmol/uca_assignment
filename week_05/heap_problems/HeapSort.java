class HeapSort {
  public static void heapSort(int[] arr) {
    int n = arr.length;
    for (int i = n / 2; i >= 0; i--) {
      heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
    }
  }

  public static void heapify(int[] arr, int n, int i) {
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int greatest = i;
    if (left < n && arr[left] > arr[greatest])
      greatest = left;
    if (right < n && arr[right] > arr[greatest])
      greatest = right;

    if (greatest != i) {
      int temp = arr[i];
      arr[i] = arr[greatest];
      arr[greatest] = temp;
      heapify(arr, n, greatest);
    }
  }

  public static void main(String[] args) {
    int[] arr = { 6, 1, 2, 3, 4, 5 };
    heapSort(arr);
  }
}
