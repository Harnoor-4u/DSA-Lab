#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node *next,*prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){
        head=nullptr;
    }


    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;

        }
    }

    void sizeDLL() {
    if (head == nullptr) {
        cout << "empty list" << endl;
        return;
    }

    Node* temp = head;
    int size=0;
    do {
       // cout << temp->data << "<->";
        temp = temp->next;
        size++;
    } while (temp != nullptr);

    cout <<"Size of the circular list is: "<<size << endl;   
}
};

int main(){

    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    dll.sizeDLL(); 
    return 0;
}