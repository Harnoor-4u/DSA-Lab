#include<iostream>
using namespace std;

//for doubly linked list

class node {
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};


void insert(node* &head, int element, int d){
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        temp->next = temp;
        return;
    }

    node* curr = head;

    // search for element (one full loop max)
    do {
        if(curr->data == element) break;
        curr = curr->next;
    } while(curr != head);

    if(curr->data != element){
        cout << "Element " << element << " not found!\n";
        return;
    }

    node* temp = new node(d);
    temp->next = curr->next;
    curr->next = temp;
}


void search(node* head, int element){
    if(head==NULL){
        cout << "List empty\n";
        return;
    }

    node* temp = head;
    do {
        if(temp->data == element){
            cout << "Element found: " << element << endl;
            return;
        }
        temp = temp->next;
    } while(temp != head);

    cout << "Element not found\n";
}


void del(node* &head,int val){
    if(!head){
        cout << "List empty\n";
        return;
    }

    node* curr = head;
    node* prev = NULL;

    // search for node
    do {
        if(curr->data == val) break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    if(curr->data != val){
        cout << "Value not found\n";
        return;
    }

    // only one node
    if(curr == head && curr->next == head){
        head = NULL;
        delete curr;
        return;
    }

    // deleting head
    if(curr == head){
        node* temp = head;
        while(temp->next != head) temp = temp->next;
        head = head->next;
        temp->next = head;
        delete curr;
        return;
    }

    // deleting non-head
    prev->next = curr->next;
    delete curr;
}


void display(node* head){
    if(!head){
        cout << "List empty\n";
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}


int main() {
    node* head = NULL;

    insert(head, 0, 10);   // first node
    display(head);

    insert(head, 10, 20);
    insert(head, 20, 30);
    insert(head, 10, 15);
    display(head);

    search(head, 20);
    search(head, 100);

    del(head, 10);
    display(head);

    del(head, 30);
    display(head);

    del(head, 15);
    display(head);

    del(head, 20);
    display(head);

    return 0;
}
