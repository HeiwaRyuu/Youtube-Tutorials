#include <stdio.h>

#define NELEMEN(x) (sizeof(x) / sizeof(x[0]))
void PrintArr(int *arr, int size);
void HeapSort(int *arr, int size);
void MaxHeapify(int *arr, int size);
void swap(int *arr, int x, int y);

int main() {
  // int arr[] = {3, 4, 1, -2, -33, 43, 1023, 32, 87, 23, 89, 2, 8, 9, 337};
  int arr[] = {0, 5, 2, 3, 7, 9, 8};
  PrintArr(arr, NELEMEN(arr));
  // swap(arr, 9, 4);
  HeapSort(arr, NELEMEN(arr));
  PrintArr(arr, NELEMEN(arr));

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
  printf("Swap: %d at index %d with %d at index %d\n", arr[x], x, arr[y], y);
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void Heapify(int *arr, int size, int i) {
  int left_child = i * 2 + 1;
  int right_child = i * 2 + 2;
  int biggest = left_child;
  if (left_child >= size) {
    return;
  }
  if (right_child < size) {
    if (arr[right_child] > arr[biggest]) {
      biggest = right_child;
    }
  }
  if (arr[biggest] > arr[i]) {
    swap(arr, biggest, i);
  }
}

void MaxHeapify(int *arr, int size) {
  for (int i = size; i >= 0; i--) {
    Heapify(arr, size, i);
  }
  swap(arr, 0, size - 1);
}

void HeapSort(int *arr, int size) {
  int min = 0;
  while (min < 2) {
    MaxHeapify(arr, size - min);
    min++;
    PrintArr(arr, size);
    printf("\n");
  }
  printf("End of HeapSort function...\n\n");
}
