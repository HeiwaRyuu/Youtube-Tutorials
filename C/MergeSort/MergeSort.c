#include <stdio.h>

#define NELEMEN(x) (sizeof(x)/sizeof(x[0]))

void PrintArray(int *arr, int size);
void MergeSort(int *arr, int size);
void Merge(int *arr, int size, int *left_arr, int left_size, int *right_arr, int right_size);
void FillArr(int *Marr, int Mindex, int *Sarr, int Ssize);

int main(){
	printf("Original Arrays:\n");
	int arr[] = {8, 3, 1, 0, 4};
	int arr2[] = {5, -8, 7, 2, 11, 12, 9, 3, 6, 35};
	int arr3[] = {2, 3, 4, 5};
	int arr4[] = {337};

	PrintArray(arr, NELEMEN(arr));
	PrintArray(arr2, NELEMEN(arr2));
	PrintArray(arr3, NELEMEN(arr3));
	PrintArray(arr4, NELEMEN(arr4));

	MergeSort(arr, NELEMEN(arr));
	MergeSort(arr2, NELEMEN(arr2));
	MergeSort(arr3, NELEMEN(arr3));
	MergeSort(arr4, NELEMEN(arr4));

	printf("\nSorted Arrays:\n");
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

void FillArr(int *Marr, int Mindex, int *Sarr, int Ssize){
	for(int i=0;i<Ssize;i++){
		Sarr[i]=Marr[Mindex];
		Mindex++;
	}
}

void Merge(int *arr, int size, int *left_arr, int left_size, int *right_arr, int right_size){
	int left = left_size-1;
	int right = right_size-1;
	int original = size-1;

	while(left>=0 && right>=0){
		if(left_arr[left]>right_arr[right]){
			arr[original]=left_arr[left];
			left--;
			original--;
		}
		else{
			arr[original]=right_arr[right];
			right--;
			original--;
		}
	}

	while(left>=0){
		arr[original]=left_arr[left];
		left--;
		original--;
	}
	while(right>=0){
		arr[original]=right_arr[right];
		right--;
		original--;
	}
}

void MergeSort(int *arr, int size){
	if(size<=1){
		return;
	}
	int mid = size/2;
	int left_size = mid;
	int right_size = size-mid;

	int left_arr[left_size];
	int right_arr[right_size];
	FillArr(arr, 0, left_arr, left_size);
	FillArr(arr, mid, right_arr, right_size);
	printf("\nOriginal Arr:\n");
	PrintArray(arr, size);
	printf("Left Arr:\n");
	PrintArray(left_arr, left_size);
	printf("Right Arr:\n");
	PrintArray(right_arr, right_size);

	MergeSort(left_arr, left_size);
	MergeSort(right_arr, right_size);
	Merge(arr, size, left_arr, left_size, right_arr, right_size);
	printf("Merged Arr:\n");
	PrintArray(arr, size);
}
