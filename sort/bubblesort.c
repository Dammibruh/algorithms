#include <stdio.h>
void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void bsort(int *arr){
	size_t size = (sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(arr[i] < arr[j]){
				swap(&arr[j], &arr[i]);
			}
		}
		
	}
}

int main(){
	int arr[5] = {1,0,5,7,9};
	bsort(arr);
	for(int x = 0; x < (sizeof(arr)/sizeof(arr[0])); x++){
		printf("%d\n", arr[x]);
	}
}
