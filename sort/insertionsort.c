#include <stdio.h>
void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void inssort(int *arr){
	size_t size = (sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i < size; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] < arr[j]){
				swap(&arr[j], &arr[i]);
			}
		}
		
	}
}

int main(){
	int arr[4] = {1,0,5,7};
	inssort(arr);
	for(int x = 0; x < 4; x++){
		printf("%d\n", arr[x]);
	}
}
