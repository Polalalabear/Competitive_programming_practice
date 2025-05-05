#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
    Node* prev;
}Node;

void insert(Node** head, int n){
    Node* node = new Node();
    node->val = n;
    node->next = nullptr;
    node->prev = nullptr;
    if(!(*head))    (*head) = node;
    else{
        Node* cur = (*head);
        while(cur->next){
            cur = cur->next;
        }
        cur->next = node;
        node->prev = cur;
    }
}

void show(Node* head){
    Node* cur = (head);
    cout << "\n============\n";
    cout << "Current linked list:\n";
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void delete_last_n_node(Node** head){
    Node* tail = *head;
    while(tail && tail->next) tail = tail->next;

    cout << "\ndelete last nth node: ";
    int n;
    cin >> n;
    n--;
    while(n-- && tail && tail->prev)    tail = tail->prev;

    if(tail && tail->prev)     tail->prev->next = tail->next;
    else    *head = tail->next;

    if(tail && tail->next)     tail->next->prev = tail->prev;

    delete tail;

    cout << "\n======Delete Completed======\n";
}

int main(){
    Node* head = nullptr;
    int n;
    for(int i=1; i<=5; i++){
        cin >> n;
        insert(&head, i);
    }
    show(head);
    delete_last_n_node(&head);
    show(head);
}