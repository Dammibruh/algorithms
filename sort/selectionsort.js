function selectsort(n){
    for(var i = 0; i < n.length;i++){
        for(var j = n.length; j > i; j--){
            if(n[j] < n[i]){
                [n[j], n[i]] = [n[i], n[j]]
            }
        }
    }
    return n
}
