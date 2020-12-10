#include <memory>
#include <iostream>

template<typename NodeType>
class List {
    std::shared_ptr<List> next;
    NodeType data;
    template<size_t N>
    void _add_nodes(const NodeType (&node)[N]){
        auto current = this;
        for(int i = 0; i <= N-1;++i){
            current->add_node(node[i]);
            current = current->getNext().get();
        }
    }
    auto _get_last_node(){
        auto current = this;
        while(current->getNext() != nullptr){
            current = current->getNext().get();
        }
        return current;
    }
    public:
    template<size_t N>
    List(const NodeType (&node)[N])
    {
            this->_add_nodes(node);
    }
    List(const NodeType& data)
        : data(data) {}
    void add_node(const NodeType& data){
        auto nextNode = std::make_shared<List<NodeType>>(data);
        this->_get_last_node()->setNext(nextNode);
    }
    void add_node_first(const NodeType& data){
        auto nnode = std::make_shared<List<NodeType>>(this->data);
        nnode.get()->setNext(this->next);
        this->data = data;
    }
    auto getNext(){
        return this->next;
    }
    void setNext(const std::shared_ptr<List<NodeType>>& node){
        this->next = node;
    }
    void pop_last(){
        auto nextn = this->next.get();
        while(nextn != nullptr){
            nextn = nextn->getNext().get();
        }
        nextn = nullptr;
    }
    void pop_first(){
        this->next = this->next.get()->getNext();
        this->data = this->next.get()->getData();
    }
    size_t getSize(){
        size_t size = 0;
        auto current = this;
        while(current->getNext() != nullptr){
            current = current->getNext().get();
            size++;
        }
        return size;
    }
    const NodeType& operator[](size_t index){
        size_t count = 0;
        auto current = this;
        while(current->getNext() != nullptr){
            current = current->getNext().get();
            count++;
            if(count-1 == index){
                return current->getData();
            }
        }
    }
    NodeType getData(){
        return this->data;
    }
};
