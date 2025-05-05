#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
}Node;

int main(){
    Node* head = nullptr;
    Node* current = nullptr;
    int n;

    while(cin >> n){
        Node* node = new Node();
        node->val = n;
        if(!head)   head = node;
        else    current->next = node;
        current = node; 
    }

    current = head;
    while(current != nullptr){
        cout << current->val << " ";
        current = current -> next;
    }

    current = head;
    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;  
    }

    return 0;
}