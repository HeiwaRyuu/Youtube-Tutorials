#include <stdio.h>

#define NELEMEN(x) (sizeof(x) / sizeof(x[0]))

void PrintArr(int *arr, int size);
int BinarySearch(int *arr, int size, int value);
void SearchAndPrint(int *arr, int size, int value);

int main() {
  int arr[] = {-5, 0, 1, 2, 6, 8, 12, 23, 54, 89};
  SearchAndPrint(arr, NELEMEN(arr), 54);
  SearchAndPrint(arr, NELEMEN(arr), -5);
  SearchAndPrint(arr, NELEMEN(arr), 89);
  SearchAndPrint(arr, NELEMEN(arr), 2);
  SearchAndPrint(arr, NELEMEN(arr), 9);
  return 0;
}

void SearchAndPrint(int *arr, int size, int value) {
  PrintArr(arr, size);
  printf("\n");
  int index = BinarySearch(arr, size, value);
  printf("\n");
  if (index == -1) {
    printf("The value %d is NOT in the array!\n", value);
  } else {
    printf("The value %d is at index %d\n", value, index);
  }
  printf("\n\n");
}

void PrintArr(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[size - 1]);
}

int BinarySearch(int *arr, int size, int value) {
  int low = 0;
  int high = size - 1;
  int mid = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    printf("Low is: %d and its value is %d\n", low, arr[low]);
    printf("High is: %d and its value is %d\n", high, arr[high]);
    printf("The mid index is %d and and its value is %d\n", mid, arr[mid]);
    if (arr[mid] == value) {
      return mid;
    }
    if (arr[mid] < value) {
      low = mid + 1;
    }
    if (arr[mid] > value) {
      high = mid - 1;
    }
  }
  return -1;
}
