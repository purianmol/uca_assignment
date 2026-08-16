#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompFunc)(void *, void *);

void show_int_array(int *arr, int len) {
  for (int k = 0; k < len; k++) {
    printf("%d ", arr[k]);
  }
  printf("\n");
}

void show_float_array(float *arr, int len) {
  for (int k = 0; k < len; k++) {
    printf("%.2f ", arr[k]);
  }
  printf("\n");
}

void show_char_array(char *arr, int len) {
  for (int k = 0; k < len; k++) {
    printf("'%c' ", arr[k]);
  }
  printf("\n");
}

void show_string_array(char **arr, int len) {
  for (int k = 0; k < len; k++) {
    printf("'%s' ", arr[k]);
  }
  printf("\n");
}

void mem_swap(void *a, void *b, int byte_size) {
  void *temp_buf = malloc(byte_size);
  memcpy(temp_buf, a, byte_size);
  memcpy(a, b, byte_size);
  memcpy(b, temp_buf, byte_size);
  free(temp_buf);
}

int compare_ints(void *a, void *b) {
  if (*(int *)a == *(int *)b)
    return 0;
  return *(int *)a > *(int *)b ? 1 : -1;
}

int compare_floats(void *a, void *b) {
  if (*(float *)a == *(float *)b)
    return 0;
  return *(float *)a > *(float *)b ? 1 : -1;
}

int compare_chars(void *a, void *b) {
  if (*(char *)a == *(char *)b)
    return 0;
  return *(char *)a > *(char *)b ? 1 : -1;
}

int compare_strs(void *a, void *b) { return strcmp(*(char **)a, *(char **)b); }

void fix_heap(void *array, int n, int idx, int item_sz, CompFunc cmp) {
  int max_idx = idx;
  int l_child = idx * 2 + 1;
  int r_child = idx * 2 + 2;

  if (l_child < n && (cmp((char *)array + max_idx * item_sz,
                          (char *)array + l_child * item_sz) < 0)) {
    max_idx = l_child;
  }

  if (r_child < n && (cmp((char *)array + max_idx * item_sz,
                          (char *)array + r_child * item_sz) < 0)) {
    max_idx = r_child;
  }

  if (max_idx != idx) {
    mem_swap((char *)array + max_idx * item_sz, (char *)array + idx * item_sz,
             item_sz);
    fix_heap(array, n, max_idx, item_sz, cmp);
  }
}

void custom_heap_sort(void *array, int n, int item_sz, CompFunc cmp) {
  for (int j = n / 2 - 1; j >= 0; j--) {
    fix_heap(array, n, j, item_sz, cmp);
  }

  for (int j = n - 1; j >= 0; j--) {
    mem_swap(array, (char *)array + j * item_sz, item_sz);
    fix_heap(array, j, 0, item_sz, cmp);
  }
}

int main(void) {
  int nums[] = {42, 7, 19, -5, 88, 3, 14, 256, 0};
  int num_len = sizeof(nums) / sizeof(nums[0]);
  printf("int array before: ");
  show_int_array(nums, num_len);
  custom_heap_sort(nums, num_len, sizeof(int), compare_ints);
  printf("int array after: ");
  show_int_array(nums, num_len);
  printf("\n");

  float floats[] = {9.99, -1.2, 5.5, 3.14, 0.0, 123.45, 77.7};
  int float_len = sizeof(floats) / sizeof(floats[0]);
  printf("float array before: ");
  show_float_array(floats, float_len);
  custom_heap_sort(floats, float_len, sizeof(float), compare_floats);
  printf("float array after: ");
  show_float_array(floats, float_len);
  printf("\n");

  char chars[] = {'c', 'o', 'm', 'p', 'u', 't', 'e', 'r',
                  ' ', 's', 'c', 'i', 'e', 'n', 'c', 'e'};
  int char_len = sizeof(chars) / sizeof(chars[0]);
  printf("char array before: ");
  show_char_array(chars, char_len);
  custom_heap_sort(chars, char_len, sizeof(char), compare_chars);
  printf("char array after: ");
  show_char_array(chars, char_len);
  printf("\n");

  char *strs[] = {"programming", "data structures", "x-ray", "apple",
                  "123 test!"};
  int str_len = sizeof(strs) / sizeof(strs[0]);
  printf("string array before: ");
  show_string_array(strs, str_len);
  custom_heap_sort(strs, str_len, sizeof(char *), compare_strs);
  printf("string array after: ");
  show_string_array(strs, str_len);

  return 0;
}
