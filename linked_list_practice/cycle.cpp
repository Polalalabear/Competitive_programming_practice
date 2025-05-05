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
        Node* node = new Node();
        cin >> n;
        node->val = n;
        if(!(*head)) *head = node;
        else    current->next = node;
        current = node;
    }
    cout << "build linked list complete.\n";
}

void make_cycle(Node** head){
    if(!(*head) || !(*head)->next)    return;
    Node* temp = *head;
    while(temp->next != nullptr)  temp = temp->next;
    temp->next = (*head)->next;
    cout << "make cycle complete.\n";
}

void show_linked_list(Node* head){
    Node* current = head;
    if(!head) cout << "null.\n";
    else{
        cout << "Current linked list:\n";
        while(current){
            cout << current->val << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

bool hasCycle(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)    return true;
    }
    return false;
}

int main(){
    Node* head = nullptr;
    build_linked_list(&head);
    show_linked_list(head);

    make_cycle(&head);

    if(hasCycle(head))  cout << "cycle exists.\n";
    else    cout << "cycle does not exist.\n";

    return 0;
}