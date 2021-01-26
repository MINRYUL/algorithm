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
#define MAX 200002
using namespace std;
int n, f, num, r[MAX], c[MAX];
map<string, int> m;
string s1, s2;

int getParent(int a){
    if(r[a] == a) return a;
    return r[a] = getParent(r[a]);
}
void sumSet(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a == b) return;
    if(a < b){
        c[a] += c[b]; c[b] = 0;
        r[b] = a;
    }else{
        c[b] += c[a]; c[a] = 0;
        r[a] = b;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        for(int i = 0; i <= MAX; i++) r[i] = i;
        memset(c, 0, sizeof(c));
        m.clear(); num = 0; cin >> f;
        for(int i = 0; i < f; i++){
            cin >> s1 >> s2;
            if(!m.count(s1))
                m.insert({s1, num}), c[num++] = 1;
            if(!m.count(s2))
                m.insert({s2, num}), c[num++] = 1;
            int a = m.find(s1)->second, b = m.find(s2)->second;
            sumSet(a, b);
            cout << c[getParent(a)] << '\n';
        }
    }
    
    return 0;
}
