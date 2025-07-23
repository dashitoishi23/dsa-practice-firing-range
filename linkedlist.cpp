#include<iostream>

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

public void insert_at_beginning(int data);
public void insert_at_end(int data);
public void print_nodes();

public void insert_at_beginning(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}
public void insert_at_end(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
       head = temp; //if no nodes in list, this becomes the head node
    else{
        Node* iter = head;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = temp;
    }
}
public void print_nodes(){
    Node* iter = head;
    while(iter->next != NULL){
        cout << iter->next << "\n";
        iter = iter->next;
    }
}
int main(){
    insert_at_end(1);
    insert_at_end(2);
    print_nodes();

    return 0;
}