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
        if(!(*head)) 
            *head = node;
        else    
            current->next = node;

        current = node;
    }
}

void show_current_list(Node** head){
    Node* current = *head;
    if((*head) == nullptr)  cout << "null.\n";
    else{
        cout << "Current list:\n";
        while(current != nullptr){
            cout << current->val << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

void deleteAtposition(Node** head, int p){
    Node* current = *head;
    int i=0;
    while(i<p-1){
        current = current->next;
        i++;
    }
    cout << "delete position: "<< p << ", value: "<< current->next->val << "\n";
    current->next = current->next->next;
}

int main(){
    Node* head = nullptr;
    build_linked_list(&head);
    show_current_list(&head);

    int n;
    cin >> n;
    deleteAtposition(&head, n);
    show_current_list(&head);

    return 0;
}