#include <stdio.h>

#define NELEMEN(x) (sizeof(x)/sizeof(x[0]))

void PrintArray(int *arr, int size);
void InsertionSort(int *arr, int size);
void swap(int *arr, int x, int y);

int main(){
	int arr[] = {6, 3, 4, 1, 0};
	int arr2[] = {11, 2, 5, 23, -1};
	int arr3[] = {5, 6, 7, 8, 9, 10};
	int arr4[] = {10};
	printf("Original Arrays:\n");
	PrintArray(arr, NELEMEN(arr));
	PrintArray(arr2, NELEMEN(arr2));
	PrintArray(arr3, NELEMEN(arr3));
	PrintArray(arr4, NELEMEN(arr4));
	InsertionSort(arr, NELEMEN(arr));
	InsertionSort(arr2, NELEMEN(arr2));
	InsertionSort(arr3, NELEMEN(arr3));
	InsertionSort(arr4, NELEMEN(arr4));
	printf("Sorted Arrays:\n");
	PrintArray(arr, NELEMEN(arr));
	PrintArray(arr2, NELEMEN(arr2));
	PrintArray(arr3, NELEMEN(arr3));
	PrintArray(arr4, NELEMEN(arr4));
	return 0;
}

void PrintArray(int *arr, int size){
	printf("[");
	for(int i=0;i<size-1;i++){
		printf("%d, ",arr[i]);
	}
	printf("%d]\n",arr[size-1]);
}

void swap(int *arr, int x, int y){
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void InsertionSort(int *arr, int size){
	if(size==1){
		return;
	}
	for(int i=1;i<size;i++){
		for(int j=i;j>0;j--){
			if(arr[j]<arr[j-1]){
				swap(arr, j, j-1);
			}
			else{
				break;
			}
		}
	}
}
