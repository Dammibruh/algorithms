#include <iostream>
#include "Vector.cpp"


int main(){
    Vector<int> vec;
    vec.pushBack(10);
    vec.pushBack(50);
    vec.pushBack(5);
    vec.popBack();
    vec.popFront();
    vec.Resize(20);
    for(auto& i : vec){
        std::cout << i << " ";
    }
}
