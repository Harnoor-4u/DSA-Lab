#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};


bool checkCL(Node* head) {
    if (head == nullptr) {
        return true;
    }

    Node* temp = head;
    do {
        temp = temp->next;
        if(temp==nullptr){
            return false;
        }
    } while (temp != head);

    cout <<"circular list"<< endl;
    return true;
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;  // make it circular

    cout<<checkCL(head)<<endl;
    return 0;
}
