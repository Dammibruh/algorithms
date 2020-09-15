fn part(arr:&mut [i32], min:isize, max:isize) -> isize{        
        let mut i = (min-1);                                       
        let pivot = arr[max as usize];                             
        for j in min..(max){
            if arr[j as usize] < pivot{                                    
                i += 1;                                                    
                arr.swap((i as usize), j as usize);                    
            }                                                      
        }                                                          
        arr.swap((i as usize + 1), max as usize);                  
        return i +1;                                           
}                                                          
fn quicksort(arr:&mut [i32], min:isize, max:isize){            
        if min < max {
           let p = part(arr, min, max);                               
           quicksort(arr, min, p-1);
           quicksort(arr, p+1, max);                              
        }
}

                                                           
fn main(){
    let mut b:[i32; 6] = [6,8,4,5,7,9];                        
    let nd:isize = (b.len()-1) as isize;
    println!("{:?}\n", b);
    quicksort(&mut b, 0, nd);
    println!("{:?}", b);
}
