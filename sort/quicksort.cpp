#include <cstdlib>
#include <algorithm>

template<typename TP, int N>
int part(TP (&arr)[N], int low, int max){
    int pivot = arr[max];
    int i = low-1;
    for(int j = low; j <= max; ++j){
        if(arr[j] < pivot){
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[max]);
    return i+1;
}

template<typename TP, int N>
void quick_sort(TP (&arr)[N], int low, int max){
    if(low < max){
        int p = part(arr, low, max);
        quick_sort(arr, low, p-1);
        quick_sort(arr, p+1, max);
    }
}
