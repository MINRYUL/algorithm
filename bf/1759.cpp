//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int l, c, r;
char x, s[] = "aeiou";
vector<char> mo, ja;
vector<string> st;
bool visitedMo[15], visitedJa[15];

void dfsJa(int a, int b, string tempMo){
    if(b == l){
        string tempJa, result;
        for(int i = 0; i < ja.size(); i++)
            if(visitedJa[i]) tempJa.push_back(ja[i]);
        result.append(tempMo); result.append(tempJa);
        sort(result.begin(), result.end());
        st.push_back(result);
    }
    for(int i = a; i < ja.size(); i++){
        if(visitedJa[i]) continue;
        visitedJa[i] = true;
        dfsJa(i, b + 1, tempMo);
        visitedJa[i] = false;
    }
}

void dfsMo(int a, int b){
    if(b > 0 && b <= (l - 2)){
        string tempMo;
        for(int i = 0; i < mo.size(); i++)
            if(visitedMo[i]) tempMo.push_back(mo[i]);
        dfsJa(0, b, tempMo);
    }
    for(int i = a; i < mo.size(); i++){
        if(visitedMo[i]) continue;
        visitedMo[i] = true;
        dfsMo(i, b + 1);
        visitedMo[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        cin >> x; r = 0;
        for(int j = 0; j < 5; j++)
            if(x == s[j]){ mo.push_back(x); r = 1; }
        if(!r) ja.push_back(x);
    }
    dfsMo(0, 0);
    sort(st.begin(), st.end());
    for(string i : st) cout << i << '\n';
    return 0;
}
