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
        while(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void insert(node* &head, int element, int d){
    
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        temp->next=temp;
    }
    
else{
    node* curr =head;
    
    while(curr->data!=element){
        curr=curr->next;
    }
    node* temp=new node(d);
    temp->next=curr->next;
    curr->next=temp;
}
}

void display(node* &head){
    node*temp=head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout<<head->data<<endl;
}

//Input: 20 → 100 → 40 → 80 → 60,

int main() {
    
    node* head=NULL;
 
    insert(head, 0, 20); 
    insert(head,20,100);
    insert(head,100,40);
    insert(head,40,80);
    insert(head,80,60);
    

    cout<<"circular linked list is : "<<endl;
    display(head);
    return 0;
}