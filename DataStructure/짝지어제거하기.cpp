#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <stdlib.h>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    st.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        char temp = st.top();
        while(!st.empty() && temp == s[i] && i < s.size()){
            st.pop(); i++;
            if(!st.empty()) temp = st.top();
        }
        if(i < s.size()) st.push(s[i]);
    }
    
    if(st.empty()) return 1;
    else return 0;
}
