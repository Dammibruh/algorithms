#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Node {
    struct Node* next;
    int data;
};
struct Node* head;

void set_head(struct Node* newH){
    head = newH;
}

struct Node* last_node(){
    struct Node* cur;
    cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    return cur;
}
int node_size(){
    struct Node* _current;
    _current = head;
    int count = 0;
    while(_current != NULL){
        _current = _current->next;
        count++;
    }
    return count;
}
void add_node(int data){
    struct Node* _next = (struct Node*)malloc(sizeof(struct Node));;
    _next->data = data;
    if(head == NULL){
        head = _next;
        head->next = NULL;
    } else {
        struct Node* l;
        l = last_node();
        l->next = _next;
    }
}
void delete_node(){
    struct Node *cur, *n;
    cur = head;
    while(cur->next != NULL){
        n = cur;
        cur = cur->next;
    }
    n->next = NULL;
}
