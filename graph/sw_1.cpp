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
#define MAX 100000
using namespace std;
int n;
char k, x, y, start;
string s;
vector<char> v;
vector<int> v2[180];
vector<int> r;
int before[180];

bool visited[180];
bool check[180];

void dfs(int x){
    if(!v2[x].size()){
        r.push_back(x);
        for(int i : r){
            char c = i;
            cout << c << ' ';
        }
        r.pop_back();
        cout << endl;
    }
    
    visited[x] = 1;
    for(char i : v2[x]){
        if(!visited[i]){
            r.push_back(x);
            dfs(i);
            r.pop_back();
        }
    }
}

int main() {
    getline(cin, s);
    cin >> n;
    memset(before, 0, sizeof(before));
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        before[y] = x;
        check[x] = 1;
        v2[x].push_back(y);
    }

    for(int i = 0; i < s.size(); i++)
        if(s[i] != ' ' && v2[s[i]].size()) dfs(s[i]);
    
    return 0;
}
