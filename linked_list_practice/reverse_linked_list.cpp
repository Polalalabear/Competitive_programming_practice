#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
}Node;

void build_linked_list(Node** head){
    Node* current = nullptr;
    int n;
    for(int i=0; i<5; i++){
        cin >> n;
        Node* node = new Node();
        node->val = n;
        if(!*head) *head = node;
        else    current->next = node;  
        current = node;
    }
}

void show_linked_list(Node** head){
    Node* current = *head;
    if(*head == nullptr)    cout << "null";
    else{
        cout << "Current list:\n";
        while(current != nullptr){
            cout << current->val << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

void reverseList(Node** head){
    Node* current = (*head);
    Node* prev = nullptr;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }        
    *head = prev;

    cout << "reverse the linked list complete.\n";
}

int main(){
    Node* head = nullptr;
    build_linked_list(&head);
    show_linked_list(&head);

    reverseList(&head);
    show_linked_list(&head);

    return 0;
}