#include <cstdlib>
#include <stdexcept>

template<typename StackType, size_t StackSize>
class Stack{
    StackType* _Data = nullptr;
    size_t _Size = 0;
    void _shift_to_right(){
        for(size_t i = StackSize; i > 0; i--){
            _Data[i] = std::move(_Data[i-1]);
        }
    }
    void _shift_to_left(){
        for(size_t i = 0; i < StackSize; i++){
            _Data[i] = std::move(_Data[i+1]);
        }
    }
    public:
    Stack(){ _Data = new StackType[StackSize]; }
    template<size_t N>
    Stack(const StackType (&arr)[N]) {
        _Data = new StackType[StackSize];
        for(size_t i = 0; i <= N-1;i++){
            push(std::move(arr[i])); // O(n²) go brrrrrrrrrrr
        }
    }
    ~Stack(){ delete[] _Data; }
    void push(const StackType& elm){
        if(_Size >= StackSize){
            throw std::range_error("maximum size exceeded");
        };
        _shift_to_right();
        _Data[0] = std::move(elm);
        _Size++;
    }
    void pop(){
        _Size--;
        _shift_to_left();
    }
    size_t Size() const {
        return _Size;
    }
    size_t Capacity() const {
        return StackSize;
    }
    StackType data() const {
        return _Data;
    }

    auto begin() const {
        return &(_Data[0]);
    }
    auto end() const {
        return &(_Data[_Size]);
    }
    StackType& operator[](size_t index){
        return _Data[index];
    }
};
