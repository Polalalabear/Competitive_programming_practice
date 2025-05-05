#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
}Node;

void insert(Node** head, int n){
    Node* node = new Node();
    node->next = nullptr;
    node->val = n;
    if(!(*head))   (*head) = node;
    else{
        Node* current = *head;
        while(current->next)    current = current->next;
        current->next = node;
    }
}

void show(Node* head){
    Node* current = head;
    cout << "\n===============\n";
    cout << "Current Node:\n";
    while(current){
        cout << current->val << " ";
        current = current->next;
    }
}

Node* merge(Node* head1, Node* head2){
    Node m;
    Node *cur = &m;
    while(head1 && head2){
        if(head1->val < head2->val){
            cur->next = head1;
            head1 = head1->next;
        }
        else{
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    } 
    cur->next = (head1) ? head1 : head2;
    cout << "\n\n======Merge Complete======\n";
    return m.next;
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n;
    for(int i=1; i<4; i++){
        cin >> n; 
        insert(&head1, n);
    }
    for(int i=1; i<4; i++){
        cin >> n; 
        insert(&head2, n);
    }

    show(head1);
    show(head2);
    Node* m = merge(head1, head2);
    show(m);

    return 0;
}