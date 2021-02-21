//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int result = 0;

void dfs(string s, string t, int I, int C, bool ch){
    if(I >= s.size()){
        if(I + C >= s.size() && I < (s.size() - 1)) t.insert(t.end(), s.begin() + I, s.end());
        if(t.size() < result) result = t.size();
        string k;
        if(s != t){
            for(int i = 1; i <= t.size(); i++){
                string k; dfs(t, k, 0, i, true);
            }
        }
        return;
    }
    string te; int n = 0, check = 0, si = 0;
    if(I + C > s.size()) si = s.size();
    else si = I + C;
    for(int i = I; i < si; i++) te.push_back(s[i]);
    for(int i = si; i < s.size(); i++){
        if(n == C){
            check += 1; n = 0;
        }
        if(te[n] != s[i]) break;
        n += 1;
    }
    if(n == C) check += 1;
    if(check){
        if(ch || (48 > t[0] && t[0] > 57)) return;
        t.append(to_string(check + 1)); t.append(te);
        dfs(s, t, I + (C * (++check)), C, ch);
    }else{
        t.append(te);
        dfs(s, t, I + C, C, ch);
    }
}

int solution(string s) {
    result = s.size();
    for(int i = 1; i <= s.size(); i++){
        string t; dfs(s, t, 0, i, false);
    }
    return result;
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string s; cin >> s; result = s.size();
    cout << solution(s) << endl;
    return 0;
}
