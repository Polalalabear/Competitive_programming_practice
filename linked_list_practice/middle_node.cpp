#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
}Node;

void insert(Node** head, int n){
    Node* node = new Node();
    node->val = n;
    node->next = nullptr;
    if(!(*head))    (*head) = node;
    else{
        Node* cur = (*head);
        while(cur->next)  cur = cur->next;
        cur->next = node;
    }
}

void show(Node* head){
    Node* cur = head;
    cout << "\n============\n";
    cout << "Current node:\n";
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
}

void find_mid_node_val(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << "\n============\n";
    cout << "Mid node value: " << slow->val;
}

int main(){
    Node* head = nullptr;
    int n;
    for(int i=0; i<4; i++){
        cin >> n;
        insert(&head, n);
    }
    show(head);
    find_mid_node_val(head);
}