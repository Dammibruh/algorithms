#include <cstdlib>
#include <iostream>

template<typename Qt, size_t Qs>
class Queue {
    Qt data[Qs];
    size_t QSize = 0;
    public:
    Queue(){};
    Queue(const Qt (&arr)[Qs]){
        for(int i = 0; i <= Qs-1; i++){
            this->enqueue(arr[i]);
        }
    }
    void dequeue(){
        if(this->QSize >= Qs){
            throw std::runtime_error("maximum capacity reached");
        }
        this->data[0] = nullptr;
        this->QSize--;
        for(int i = 0; i <= QSize-1; i++){
            this->data[i] = this->data[i+1];
        }
    }
    void enqueue(const Qt& elm){
        if(this->QSize >= Qs){
            throw std::runtime_error("maximum capacity reached");
        }
        this->data[this->QSize] = elm;
        this->QSize++;
    }
    size_t size(){
        return this->QSize;
    }
    size_t capacity(){
        return Qs;
    }
    bool empty(){
        return this->QSize == 0;
    }
    void clear(){
        this->data = this->data[Qs];
        this->QSize = 0;
    }
    bool full(){
        return (this->QSize == Qs);
    }
    auto begin(){
        return &(this->data[0]);
    }
    auto end(){
        return &(this->data[QSize]);
    }
};
