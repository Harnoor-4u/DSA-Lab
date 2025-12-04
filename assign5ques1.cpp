class node{
    public:
   int data;
   node*next;
   
   node(int d){
       this->next=NULL;
       this->data=d;
   }
   ~node(){
       int val=this->data;
       if(this->next != NULL){
           delete next;
           this->next=NULL;
       }
   }
};

//INSERT AT BEGNING
void beg(node* &head, int d){
   node* temp=new node(d);
   temp->next=head;
   head=temp;
}

//INSERT AT END
void end(node* &tail, int d){
   node* temp=new node(d);
   tail->next=temp;
   tail=temp;
}

//INSERT IN MIDDLE
void mid(node* &head,node* &tail,int d,int pos){
   node* temp=head;
   int ct=1;
   
     if(pos==1){
       beg(head,d);
   }
   
   //TRAVESAL
   while (ct<pos-1){
       temp=temp->next;
       ct++;
   }
   
    if(temp->next==NULL){
       end(tail, d);
       return;
   }
   node*insert=new node(d);
   insert->next=temp->next;
   temp->next=insert;
}

void delbeg(node* &head){
   node*temp=head;
   head=head->next;
   temp->next=NULL;
   delete temp;
}

void delpos(node* &head,int pos){
   
   if(pos==1){
       delbeg(head);
   }
   else{
       node* current=head;
       node* prev=NULL;
       int ct=1;
       while(ct<pos&& current != NULL){
           prev=current;
           current =current ->next;
           ct++;
       }
       
       prev->next=current ->next;
       current ->next=NULL;
       delete current;
   }
}

void displayct(node* &head, int key){
   node* temp=head;
   int ct=1;//count from head
   while(temp->data!=key&&temp!=NULL){
       ct++;
       temp=temp->next;
   }
   cout<<"the position of node from head is : "<<ct<<endl;
       if (temp == NULL)
       cout << "Key not found\n";
   else
       cout << "Position from head: " << ct << endl;
}

//DISPLAYING DATA
void display(node* &head){
   node* temp=head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
   }
   cout<<endl;
}


int main() {
   node* node1=new node(10);
   node* head=node1;
   node* tail =node1;
   
   beg(head,5);
   end(tail,45);
   mid(head,tail,30,3);
   mid(head,tail,35,4);
   mid(head,tail,35,3);
   mid(head,tail,60,2);
   display(head);

   delpos(head,3);
   delpos(head,2);
   display(head);
   cout<<endl;
   displayct(head,30);

   return 0;
}