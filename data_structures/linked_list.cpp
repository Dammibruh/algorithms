#include <iostream>
class Node{
public:
    int data;
    Node *next;
};
int main(){
   Node node;
   Node node2;
   node.data = 1;
   node2.data = 2;
   node.next = &node2;
   std::cout << node.next->data;
}
