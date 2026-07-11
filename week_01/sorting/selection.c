#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int n){
  int* arr = (int *)malloc(n * sizeof(int));
  for(int i = 0;i<n;i++){
    arr[i] = rand();
  }
  return arr;
}

int *generateAscArray(int n){
  int* arr = (int *)malloc(n * sizeof(int));
  for(int i = 0;i<n;i++){
    arr[i] = i;
  }
  return arr;
}

int *generateDescArray(int n){
  int* arr = (int *)malloc(n * sizeof(int));
  for(int i = 0;i<n;i++){
    arr[i] = n-i;
  }
  return arr;
}

void applySelectionSort(int arr[],int n){
  for(int i = 0;i<n;i++){
    int min = i;
    for(int j = i+1;j<n;j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    if(min != i){
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp; 
    }
  }
}

bool verifySort(int arr[],int n){
  for(int i = 1;i<n;i++){
    if(arr[i]<arr[i-1])return false;
  }
  return true;
}

// Analyzes the time taken
void analyze(int arr[],int n){
  // start time
  clock_t start = clock();
  // sorting algoritm
  applySelectionSort(arr,n);
  // stop time
  clock_t end = clock();
  
  double execTime = (double)(end - start) / CLOCKS_PER_SEC;

  if(!verifySort(arr,n)){
    printf("Failed: array not sorted");
    exit(-1);
  }
  printf("%.0f\n",execTime*1000);

  free(arr);
}

int main(){
  printf("Selection Sort for random data (Execution Time in ms):\n");
  for(int n = 8000;n<=36000;n+=4000){
    int* arr = generateRandomArray(n);
    analyze(arr,n);
  }
  printf("Selection Sort for ascending data (Execution Time in ms):\n");
  for(int n = 8000;n<=36000;n+=4000){
    int* arr = generateAscArray(n);
    analyze(arr,n);
  }
  printf("Selection Sort for descending data (Execution Time in ms):\n");
  for(int n = 8000;n<=36000;n+=4000){
    int* arr = generateDescArray(n);
    analyze(arr,n);
  }
  return 0;
}
