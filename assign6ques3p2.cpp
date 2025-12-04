#include <iostream>
using namespace std;

//for circular linked list


class node{
    public:
    node*next;
    int data;
    
    node(int d){
        this->next=NULL;
        this->data=d;
    }
};

void insert(node* &head, int element,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        temp->next=temp;
    }
    else{
        node*curr=head;
        while(curr->data!=element){
            curr=curr->next;
        }
        
        node*temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void display(node* &head){
    node* temp=head;
    int ct=0;
    
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
        ct++;
    }while(temp!=head);
    
    cout<<head->data<<endl;
    cout<<endl<<"size of linked list is "<<ct<<endl;
}

int main(){
    node* head=NULL;
    insert(head, 0, 20); 
    insert(head,20,100);
    insert(head,100,40);
    insert(head,40,80);
    insert(head,80,60);
    cout<<"linked list is : "<<endl;
    display(head);
}