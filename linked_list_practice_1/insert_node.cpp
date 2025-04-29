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
        cin>>n;
        Node* node = new Node();
        node->val = n;
        if(!(*head))   *head = node;
        else    current->next = node;
        current = node;
    }
}

void show_current_list(Node** head){
    Node* current = *head;
    if(*head == nullptr) cout << "null\n";
    else{
        cout << "Current list:\n";
        while(current != nullptr){
            cout << current->val << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

void insertAtEnd(Node** head, int n){
    Node* current = *head;
    cout << "Insert "<< n << " in tail.\n";
    while(*head == nullptr) cout << "null.\n";
    while(current->next != nullptr){
        current = current->next;
    }
    Node* temp = new Node();
    temp->val = n;
    temp->next = nullptr;
    current->next = temp;    
}

int main(){
    Node* head = nullptr;
    build_linked_list(&head);
    show_current_list(&head);
    int n;
    cin >> n;
    insertAtEnd(&head, n);
    show_current_list(&head);
}