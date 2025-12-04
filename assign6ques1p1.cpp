#include <iostream>
using namespace std;
//for doubly linked list


class node {
    public:
        int data;
        node* next;
        node* prev;
    
        node(int d) {
            this->data = d;
            this->next = NULL;
            this->prev = NULL;
        }
    
        ~node() {
            this->next = NULL;
            this->prev = NULL;
        }
    };
    
    
    void start(node*& head, node*& tail, int d) {
        node* temp = new node(d);
    
        if (head == NULL) {           
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    
    
    void end(node*& head, node*& tail, int d) {
        node* temp = new node(d);
    
        if (tail == NULL) {          
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    
    void pos(node*& head, node*& tail, int d, int position) {
        if (position == 1) {
            start(head, tail, d);
            return;
        }
    
        int cnt = 1;
        node* curr = head;
    
        while (cnt < position - 1 && curr != NULL) {
            curr = curr->next;
            cnt++;
        }
    
        if (curr == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
    
        if (curr->next == NULL) {     // insert at end
            end(head, tail, d);
            return;
        }
    
        node* newNode = new node(d);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
    
    void search(node* head, int element) {
        node* temp = head;
    
        while (temp != NULL) {
            if (temp->data == element) {
                cout << "Element found: " << element << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Element NOT found: " << element << endl;
    }
    
    void del(node*& head, node*& tail, int position) {
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
    
        if (position == 1) {
            node* temp = head;
    
            if (head->next == NULL) {     // one node
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->next;
                head->prev = NULL;
            }
    
            delete temp;
            return;
        }
    
        int cnt = 1;
        node* curr = head;
    
        while (cnt < position && curr != NULL) {
            curr = curr->next;
            cnt++;
        }
    
        if (curr == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
    
        if (curr->next == NULL) {     // last node
            tail = curr->prev;
            tail->next = NULL;
            delete curr;
            return;
        }
    
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    
        delete curr;
    }
    
    void display(node* head) {
        node* temp = head;
    
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    int main() {
        node* head = NULL;
        node* tail = NULL;
    
        // INSERT at start
        start(head, tail, 10);
        start(head, tail, 5);
        cout << "After inserting at start: ";
        display(head);
    
        // INSERT at end
        end(head, tail, 20);
        end(head, tail, 25);
        cout << "After inserting at end: ";
        display(head);
    
        // INSERT at position
        pos(head, tail, 15, 3);
        cout << "After inserting 15 at position 3: ";
        display(head);
    
        // SEARCH
        search(head, 20);
        search(head, 100);
    
        // DELETE nodes
        del(head, tail, 1);
        cout << "After deleting position 1: ";
        display(head);
    
        del(head, tail, 3);
        cout << "After deleting position 3: ";
        display(head);
    
        del(head, tail, 4);
        cout << "After deleting last node: ";
        display(head);
    
        return 0;
    }
    