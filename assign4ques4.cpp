// time complexity: O(n)
// space complexity: O(n)

#include<iostream>
#include<stack>
#include<queue>
using namespace std;





void interleaveQueue(queue<int> &q){
    // QUEUE:  4 7 11 20 5 9

    if(q.size()%2!=0){
        cout<<"enter the queue with even number of elements!"<<endl;

    }

    stack<int> s;

    int halfsize=q.size()/2;
    //push first half elements into the stack
    for(int i=0;i<halfsize;i++){
        s.push(q.front());
        q.pop();
    }               //  now --> STACK:4 7 11         QUEUE: 20 5 9


    //enqueue back the stack element
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }                           // now --> QUEUE: 20 5 9 11 7 4 


    //now again dequeue first half elements and then enqueue them back
    for(int i=0;i<halfsize;i++){
        q.push(q.front());
        q.pop();
    }                           // now ---> QUEUE: 11 7 4 20 5 9


    // again push the first half into the stack
    for(int i=0;i<halfsize;i++){
        s.push(q.front());
        q.pop();
    }                           // now ---> STACK: 11 7 4        QUEUE: 20 5 9


    //INTERLEAVE THE ELEMENTS OF QUEUE
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();

    }
}


int main(){
    queue<int>q;

    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}