#include <iostream>


class Node{
public:
    int data;
    Node *next;
};
void getNode(Node *node){
	int count = 1;
	Node *cur = node;
	while(cur->next){
		cur = cur->next;
		count++;
	}
	std::cout << "Total connected nodes is " << count;
}
int main(){
   Node node;
   Node node2;
   Node node3;
   Node node4;
   node.data = 1;
   node2.data = 2;
   node3.data = 3;
   node4.data = 4;
   node.next = &node2;
   node2.next = &node3;
   node3.next = &node4;
   getNode(&node);
   //should print 4
}
