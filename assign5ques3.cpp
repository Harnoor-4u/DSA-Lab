#include<iostream>
using namespace std;

class node{
    public:
    node*next;
    int data;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void end(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void display(node* head){
     node*temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
}


node* getmid(node* head){
    if(head == NULL || head->next == NULL)
        return head;

    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main(){
    node* node1=new node(1);
    node* head=node1;
    node*tail=node1;
    
    end(tail,2);
    end(tail,3);
    end(tail,4);
    end(tail,5);
    display(head);
    cout<<endl;
    node* mid=getmid(head);
    cout<<"the mid of the linked list is : "<<mid->data<<endl;
}
