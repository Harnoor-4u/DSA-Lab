#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string &str) {
        stack<char> st;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            }

            else {
                if(st.empty()) return false;
                
                char ch = str[i];
                if (ch == ')') {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                }

                else if (ch == ']') {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                }

                else if(ch == '}'){
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }

            
        }
        if (st.size() != 0) return false;

            return true;
        //Time Complexity: O(N);
        //Space Complexity: O(N);
    }

    int main(){
        
        string prt="()[{}()]";

        cout<<"Are Parenthesis Balanced:  ";
        string s= (isBalanced(prt)==1)? "Yes" : "No";
        cout<<s;
        return 0;
    }