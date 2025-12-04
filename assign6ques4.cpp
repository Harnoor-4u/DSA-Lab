#include<iostream>
using namespace std;


class Node{
public:
    char data;
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


    void insertAtEnd(char ch){
        Node* newNode=new Node(ch);
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

    void display(){
        if(head==nullptr){
            cout<<"empty list"<<endl;
            return;            
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }

    bool checkPalindrome(){
        bool isPalindrome=true;
        if(head==nullptr){
            cout<<"empty list"<<endl;
            return isPalindrome;            
        }
        Node* end=head;
        while(end->next!=nullptr){
            end=end->next;
        }
        Node* start=head;
        
        while (start != end && end->next != start) {
        if (start->data != end->data) {
            cout << "\nNOT PALINDROME!!" << endl;
            isPalindrome=false;
            return isPalindrome;
        }
        start = start->next;
        end = end->prev;
        }

        cout << "\nPALINDROME!!" << endl;
        return isPalindrome;
}
        

};

int main(){

    DoublyLinkedList dll;

    dll.insertAtEnd('L');
    dll.insertAtEnd('E');
    dll.insertAtEnd('V');
    dll.insertAtEnd('E');
    dll.insertAtEnd('L');

    dll.display(); 
    cout<<dll.checkPalindrome()<<endl;
    return 0;
}