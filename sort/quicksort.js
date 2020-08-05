function part(array, low, max){
   var pivot = array[max]
   var i = low-1
   for(var j = low; j <= max-1;j++){
       if(array[j] < pivot){
           i ++
           [array[i], array[j]] = [array[j], array[i]]
           }
    }
    [array[i+1], array[max]] = [array[max], array[i+1]]
    return i+1
}
function quicksort(arr, low, high){
    if(low < high){
        p = part(arr, low, high)
        quicksort(arr,low, p-1);
        quicksort(arr, p+1, high);
    }
}
var arr = [5,6,3,7,0,0,6,5,4,7]
quicksort(hm, 0, arr.length-1)
