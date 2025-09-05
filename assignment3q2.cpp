#include<iostream>
#include<stack>
using namespace std;

void ReverseString(string &s){
    stack<char>st;
    int n=s.length();
    for(int i=0; i<n; i++){
        st.push(s[i]);
    }

    for(int i=0; i<n; i++){
        s[i]=st.top();
        st.pop();
    }
    //Time Complexity: O(2N);
    //Space Complexity: O(N);
}

int main(){
    string sg="DataStructure";
    ReverseString(sg);
    cout<<sg;

    return 0;
}