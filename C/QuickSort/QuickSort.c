#include <stdio.h>

#define NELEMEN(x) (sizeof(x)/sizeof(x[0]))

void PrintArray(int *arr, int size);
void QuickSort(int *arr, int start, int end);
int Partitioning(int *arr, int start, int pivot);
void swap(int *arr, int x, int y);

int main(){
	printf("Original Arrays:\n");
	int arr[] = {8, 3, 1, 0, 4};
	int arr2[] = {12, 17, 8, 2, 4, 9, -1, -2, 0, 19, 12};
	int arr3[] = {45, 46, 47};
	int arr4[] = {337};
	int arr5[] = {10, 9, 8, 7, 6, 5};
	int arr6[] = {-1, -2};

	PrintArray(arr, NELEMEN(arr));
	PrintArray(arr2, NELEMEN(arr2));
	PrintArray(arr3, NELEMEN(arr3));
	PrintArray(arr4, NELEMEN(arr4));
	PrintArray(arr5, NELEMEN(arr5));
	PrintArray(arr6, NELEMEN(arr6));
	
	QuickSort(arr, 0, NELEMEN(arr)-1);
	QuickSort(arr2, 0, NELEMEN(arr2)-1);
	QuickSort(arr3, 0, NELEMEN(arr3)-1);
	QuickSort(arr4, 0, NELEMEN(arr4)-1);
	QuickSort(arr5, 0, NELEMEN(arr5)-1);
	QuickSort(arr6, 0, NELEMEN(arr6)-1);
	
	printf("\nSorted Arrays:\n");
	PrintArray(arr, NELEMEN(arr));
	PrintArray(arr2, NELEMEN(arr2));
	PrintArray(arr3, NELEMEN(arr3));
	PrintArray(arr4, NELEMEN(arr4));
	PrintArray(arr5, NELEMEN(arr5));
	PrintArray(arr6, NELEMEN(arr6));

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

int Partitioning(int *arr, int start, int pivot){
	int j = start;
	int i = start;
	while(j<pivot){
		if(arr[j]<arr[pivot]){
			if(i!=j){
				swap(arr, i, j);
			}
			i++;
		}
		j++;
	}
	if(pivot!=i){
		swap(arr, i, pivot);
	}
	return i;
}

void QuickSort(int *arr, int start, int end){
	if(end>start){
		int pivot = end;
		pivot = Partitioning(arr, start, pivot);
		QuickSort(arr, 0, pivot-1);
		QuickSort(arr, pivot+1, end);
	}
}
