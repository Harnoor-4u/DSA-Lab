#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;
    node(int data){
        this->data=data;
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

void end(node* &tail, int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}
node* reverse(node* head){
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
     return prev;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* node1=new node(1);
    node*head=node1;
    node*tail=node1;
    
    end(tail,2);
    end(tail,3);
    end(tail,4);
    cout<<"Original series"<<endl;
    display(head);
    head=reverse(head);
    cout<<"reversed series"<<endl;
    display(head);
  
}
