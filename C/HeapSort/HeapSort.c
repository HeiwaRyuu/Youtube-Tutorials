#include <stdio.h>

#define NELEMEN(x) (sizeof(x) / sizeof(x[0]))

void PrintArr(int *arr, int size);
void HeapSort(int *arr, int size);
void MaxHeapify(int *arr, int size);
void Heapify(int *arr, int size, int i);
void swap(int *arr, int x, int y);

int main() {
  int arr[] = {0, 3, 8, 4, 1};
  int arr2[] = {34, 89, 102, 337, -2, -78, 3, 1, 9, 7, 22, 34, 89};
  int arr3[] = {335, 336, 337};
  int arr4[] = {337};
  printf("Original Arrays:\n");
  PrintArr(arr, NELEMEN(arr));
  PrintArr(arr2, NELEMEN(arr2));
  PrintArr(arr3, NELEMEN(arr3));
  PrintArr(arr4, NELEMEN(arr4));

  HeapSort(arr, NELEMEN(arr));
  HeapSort(arr2, NELEMEN(arr2));
  HeapSort(arr3, NELEMEN(arr3));
  HeapSort(arr4, NELEMEN(arr4));

  printf("\nSorted Arrays:\n");
  PrintArr(arr, NELEMEN(arr));
  PrintArr(arr2, NELEMEN(arr2));
  PrintArr(arr3, NELEMEN(arr3));
  PrintArr(arr4, NELEMEN(arr4));

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
  int biggest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;
  if (left_child < size && arr[left_child] > arr[biggest]) {
    biggest = left_child;
  }
  if (right_child < size && arr[right_child] > arr[biggest]) {
    biggest = right_child;
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
    PrintArr(arr, size);
  }
  printf("\n\n");
}
