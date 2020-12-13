#include <iostream>
#include "Stack.cpp"
#include "Vector.cpp"

template<typename T>
void printDs(const T& ds){
    std::cout << "{ ";
    for(auto&i : ds){
        std::cout << i << " ";
    }
    std::cout << "}\n";
}

void vectorMain(){
    Vector<int> vector({5,9,5,8,4,2,8,0,8});
    vector.popBack();
    vector.popFront();
    printDs(vector);
}

void stackMain(){
    Stack<int, 50> stack({5,8,5,6});
    stack.push(50);
    stack.push(2);
    stack.pop();
    printDs(stack);
}


int main(){
    vectorMain();
    stackMain();
}
