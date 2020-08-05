#include <iostream>

using namespace std;

template <typename S>
void bsort(S *arr){
	int size = 5;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] < arr[j]){
				swap(arr[j], arr[i]);
			}
		}
	}
}
int main(){
	int test[5] = {5,7,3,2,5};
	bsort(test);
	for(auto i : test){
		cout << i << endl;
	}
}
