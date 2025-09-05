#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int topI;

    public:
     Stack(){
        size=10;
        arr= new int[size];
        topI=-1;
     }
     bool isFull(){
        if(topI == size-1){
            cout<<endl<<"Stack is full"<<endl;
            return true;
            
        }

        return false;
        //Time Complexity: O(1);
     }
     void push(int x){
       if(isFull()) return;

        topI++;
        arr[topI]=x;
        //Time Complexity: O(1);
        //Space Complexity: O(1);
        }
     bool isEmpty(){
        if( topI == -1){
            cout<<endl<<"Stack is empty"<<endl;
            return true;
            
        }
        return false;
        //Time Complexity: O(1);
     }
     void pop(){
        if(isEmpty()) return;

        topI--;
        //Time Complexity: O(1);
     }

     int peek(){
        if(isEmpty()) return -1;

        return arr[topI];
        //Time Complexity: O(1);
     }

     void Display(){
        if(isEmpty()) return;
        cout<<"Stack is: ";
        for(int i=topI; i>=0; i--){
              cout<<"\t"<<arr[i];
        }
        //Time Complexity: O(N);
     }
};


int main(){
    Stack st;
    st.push(4);
    st.push(7);
    st.push(3);
    st.push(2);
    cout<<st.peek()<<endl;
    st.pop();
    st.Display();
    st.pop();
    cout<<st.isFull();
    st.pop();
    st.pop();
    st.peek();
    st.isEmpty();
    
    return 0;
}