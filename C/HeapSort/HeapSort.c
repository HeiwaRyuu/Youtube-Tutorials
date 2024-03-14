#include <stdio.h>

#define NELEMEN(x) (sizeof(x) / sizeof(x[0]))
void PrintArr(int *arr, int size);
void HeapSort(int *arr, int size);
void MaxHeapify(int *arr, int size);
void swap(int *arr, int x, int y);

int main() {
  int arr[] = {0, 3, 4, 4, 1};
  int arr2[] = {0, 5, 2, 3, 7, 9, 8};
  int arr3[] = {3, 4, 1, -2, -33, 43, 1023, 32, 87, 23, 89, 2, 8, 9, 337};
  printf("Original Arrays:\n");
  PrintArr(arr, NELEMEN(arr));
  // PrintArr(arr2, NELEMEN(arr2));
  //  PrintArr(arr3, NELEMEN(arr3));
  HeapSort(arr, NELEMEN(arr));
  // HeapSort(arr2, NELEMEN(arr2));
  // HeapSort(arr3, NELEMEN(arr3));
  printf("Sorted Arrays:\n");
  PrintArr(arr, NELEMEN(arr));
  // PrintArr(arr2, NELEMEN(arr2));
  // PrintArr(arr3, NELEMEN(arr3));

  return 0;
}

void PrintArr(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[size - 1]);
}

void swap(int *arr, int x, int y) {
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void Heapify(int *arr, int size, int i) {
  int left_child = i * 2 + 1;
  int right_child = i * 2 + 2;
  int biggest = i;
  if (left_child >= size) {
    return;
  }
  if (right_child < size && arr[right_child] > arr[biggest]) {
    biggest = right_child;
  }
  if (left_child < size && arr[left_child] > arr[biggest]) {
    biggest = left_child;
  }
  if (biggest != i) {
    swap(arr, biggest, i);
    Heapify(arr, size, biggest);
  }
}

void MaxHeapify(int *arr, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    Heapify(arr, size, i);
  }
}

void HeapSort(int *arr, int size) {
  for (int i = size - 1; i >= 0; i--) {
    MaxHeapify(arr, i + 1);
    PrintArr(arr, size);
    swap(arr, 0, i);
  }
}
