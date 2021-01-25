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
#define MAX 101
using namespace std;
vector<int> g[MAX];
bool visited[MAX];
int n, m, s, e, x, y, r;

void dfs(int a, int b){
    visited[a] = true;
    if(a == e) r = b;
    for(int i : g[a])
        if(!visited[i]) dfs(i, b + 1);
}

int main(void) {
    cin >> n >> s >> e >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    
    dfs(s, 0);
    if(!r) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}
