//just quicksort with pivot of median make it O(n*log(n)) fast as fuck boi
function mid(array, low, high){
	   _mid = Math.floor((low+high)/2)
	   if(array[high] < array[low]){
	   	[array[low],array[high]] = [array[high], array[low]]
	   }
	   if(array[high] < array[_mid]){
	   	  [array[high], array[_mid]] = [array[_mid], array[high]]
	   }
	   if(array[_mid] < array[low]){
	    [array[_mid], array[low]] = [array[low], array[_mid]]
	   }
	   return _mid
	   
	}

function part(array, low, _max){
   var pivot = array[mid(array, low, _max)];
   var i = low-1
   for(var j = low; j <= _max-1;j++){
       if(array[j] <= pivot){
       	i++;
           [array[i], array[j]] = [array[j], array[i]]
           
       }
    }
    [array[i+1], array[_max]] = [array[_max], array[i+1]]
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
quicksort(arr, 0, arr.length-1)
