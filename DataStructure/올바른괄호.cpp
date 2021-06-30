#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(char a : s){
        if(st.empty()){
            if(a == ')') return false;
            st.push(a);
        } else {
            if(a == '(') st.push(a);
            else st.pop();
        }
    }
    
    if(!st.empty()) return false;
    return true;
}
