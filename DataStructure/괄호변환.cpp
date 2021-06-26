#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string divideConquer(string s){
    stack<char> st;
    int leftParentheses = 0, rightParentheses = 0, index = 0;
    for(int i = 0; i < s.size(); i++){
        if(!i) st.push(s[i]);
        else if(!st.empty()){
            char a = st.top();
            if(a == '(' && s[i] == ')') st.pop();
            else st.push(s[i]);
        }
        if(s[i] == '(') leftParentheses += 1;
        else rightParentheses += 1;
        if((leftParentheses == rightParentheses) && leftParentheses){
            index = i; break;
        }
    }
    
    string u, v; 
    for(int i = 0; i <= index; i++) u.push_back(s[i]);
    if(index < s.size() - 1){
        for(int i = index + 1; i < s.size(); i++) v.push_back(s[i]);
    }
    
    if(st.empty()){
        if(!v.empty())
            u.append(divideConquer(v));
        return u;
    }
    string result, tempU;
    result.push_back('(');
    if(!v.empty())
        result.append(divideConquer(v));
    result.push_back(')');
    u.erase(0, 1); u.pop_back();
    
    for(int i = 0; i < u.size(); i++){
        if(u[i] == '(') tempU.push_back(')');
        else tempU.push_back('(');
    }
    result.append(tempU);
    return result;
}

string solution(string p) {
    return divideConquer(p);
}
