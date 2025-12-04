// time complexity: O(n)
// space complexity: O(n)

#include<iostream>
#include<queue>
using namespace std;

//STACK IMPLEMENTATION USING 2 QUEUES

class MyStack{
public:
queue<int> q1;
queue<int> q2;


MyStack(){
}

void push(int x){       //O(n)
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);

    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }


}

int pop(){
    if (q1.empty()) {
        cout << "Stack Underflow! Cannot pop." << endl;
        return -1;
    }
    int ans=q1.front();
    q1.pop();
    return ans;
}


int top(){
    if (q1.empty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return q1.front();
}

bool empty(){
    return q1.empty();
}

};



// STACK IMPLEMENTATION USING SINGLE QUEUE

class MyStack2{
public:
    queue<int> q;

    MyStack2() {}

    // Push operation (O(n))
    void push(int x) {
        q.push(x);  // insert element at back

        // Rotate queue to move new element to front
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation (O(1))
    int pop() {
        if (q.empty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    // Top element (O(1))
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    // Check if empty
    bool empty() {
        return q.empty();
    }
};


int main() {
    MyStack st;
    

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  
    cout << "Popped: " << st.pop() << endl;      
    cout << "Top element: " << st.top() << endl; 

    cout << "Popped: " << st.pop() << endl;      
    cout << "Popped: " << st.pop() << endl;      

    if (st.empty())
        cout << "Stack is empty now!\n\n" << endl;




// for second stack---->

    MyStack2 s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  
    cout << "Popped: " << s.pop() << endl;      
    cout << "Top element: " << s.top() << endl; 

    cout << "Popped: " << s.pop() << endl;      
    cout << "Popped: " << s.pop() << endl;      

    if (s.empty())
        cout << "Stack is empty now!" << endl;

    return 0;
}