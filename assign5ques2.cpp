#include<iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;
    
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void end(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void count(node* head,int key){
    node* temp=head;
    int ct=0;
    while (temp != NULL) {
        if (temp->data == key) {
            ct++;
        }
        temp = temp->next;
    }
    cout<<"count for key is : "<<ct<<endl;
}



// Deleting all occurrences of a key
void deleteAll(node*& head, int key) {
    
    while (head && head->data == key) {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            node* temp = cur->next;
            cur->next = temp->next;
            temp->next = NULL;
            delete temp;
        } 
        else {
            cur = cur->next;
        }
    }
}


void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* node1=new node(1);
    node* tail=node1;
    node*head=node1;
    
    cout<<"original series"<<endl;
    end(tail,2);
    end(tail,1);
    end(tail,2);
    end(tail,1);   
    end(tail,3);
    end(tail,1);
    display(head);
    
    count(head, 1);
    cout<<"series after deletion"<<endl;
    deleteAll(head,1);
    display(head);
}
