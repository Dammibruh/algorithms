#include <cstdlib>
template<typename VectorType>
class Vector {
    size_t _Capacity = 200;
    size_t _Size = 0;
    VectorType* _Data = nullptr;
    void Realloc(size_t new_Capacity){
        if(new_Capacity > _Capacity){
            _Capacity = new_Capacity;
            VectorType* temp = new VectorType[new_Capacity];
            for(int i = 0; i < _Capacity; ++i){
                temp[i] = std::move(_Data[i]);
            }
            _Data = temp;
            delete [] temp;
        }
    }
    void _shift_to_left(){
        for(int i = 0; i < _Capacity; i++){
            _Data[i] = _Data[i+1];
        }
    }
    void _shift_to_right(){
        for(int i = _Capacity; i > 0; i--){
            _Data[i] = _Data[i-1];
        }
    }
    void _shift_to_left_from(int index){
        for(int i = index; i < _Capacity; i++){
            _Data[i] = _Data[i+1];
        }
    }
    void _shift_to_right_from(int index){
        for(int i = _Capacity; i > index; i--){
            _Data[i] = _Data[i-1];
        }
    }
    public:
    Vector(){
        _Data = new VectorType[_Capacity];
    }
    ~Vector(){
        delete [] _Data;
    }
    void pushBack(const VectorType& element){
        _Size++;
        if(_Size >= _Capacity){
            Realloc(_Size + 50);
            _Data[_Size-1] = element;
        }
        _Data[_Size-1] = element;
    }
    void popBack(){
        if(_Size > 0){
            _Size--;
            _shift_to_left_from(_Size);
        }
    }
    void pushFront(const VectorType& element){
        _Size++;
        if(_Size >= _Capacity){
            Realloc(_Capacity + 50);
            _shift_to_right();
            _Data[0] = element;
        }
        _shift_to_right();
        _Data[0] = element;
    }
    void popFront(){
        if(_Size > 0){
            _Size--;
            _shift_to_left_from(0);
        }
    }
    bool isEmpty(){
        return (_Size == 0);
    }
    size_t Size(){
        return _Size;
    }
    size_t Capacity(){
        return _Capacity;
    }
    size_t Max_Size(){
        return _Capacity;
    }
    auto begin(){
        return &(_Data[0]);
    }
    auto end(){
        return &(_Data[_Size]);
    }
    void Resize(size_t _newSize){
        if(_newSize >= _Capacity && _newSize != _Size){
            Realloc(_Capacity + 50);
            _Size = _newSize;
        } else if(_newSize < _Capacity && _newSize != _Size){
            _Size = _newSize;
        }
    }
};
