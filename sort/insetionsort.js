do run js
function selectsort(n){
    for(var i = 0; i < n.length;i++){
        for(var j = 0; j < i; j++){
            if(n[i] < n[j]){
                [n[j], n[i]] = [n[i], n[j]]
            }
        }
    }
    return n
}
