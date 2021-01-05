//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#define MAX 10001
using namespace std;
int v, e, x, y, num, r, discovered[MAX], scc[MAX];
vector<int> g[MAX];
vector<vector<int>> res;
stack<int> st;

int dfs(int node){
    int ret = discovered[node] = ++num;
    st.push(node);
    for(int i : g[node]){
        if(discovered[i] == -1) ret = min(ret, dfs(i));
        else if(scc[i] == -1) ret = min(ret, discovered[i]);
    }
    if(ret == discovered[node]){
        vector<int> tmp;
        while(true){
            int t = st.top(); st.pop();
            scc[t] = r; tmp.push_back(t);
            if (t == node)break;
        }
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
        ++r;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e; memset(discovered, -1, sizeof(discovered));
    memset(scc, -1, sizeof(scc));
    while(cin >> x >> y) g[x].push_back(y);
    for(int i = 1; i <= v; i++) if(discovered[i] == -1) dfs(i);
    cout << res.size() << endl; sort(res.begin(), res.end());
    for(vector<int> i : res){
        for(int j = 0; j < i.size(); j++) cout << i[j] << ' ';
        cout << - 1 << endl;
    }
    return 0;
}
