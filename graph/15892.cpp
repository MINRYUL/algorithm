//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 301
#define INF 987654321

using namespace std;

int n, m, ans, c[MAX][MAX], f[MAX][MAX];
vector<int> v[MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    while(m--){
        int from, to, x;
        cin >> from >> to >> x;
        
        c[from][to] += x;
        c[to][from] += x;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    while(1){
        int prev[MAX], flow = INF;
        memset(prev, -1, sizeof(prev));
        
        queue<int> q; q.push(1);
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i : v[cur]){
                if(prev[i] != -1) continue;
                if(c[cur][i] - f[cur][i] > 0){
                    q.push(i); prev[i] = cur;
                    if(i == n)  break;
                }
            }
        }
        if(prev[n] == -1) break;
        
        for(int i = n; i != 1; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
    
        for(int i = n; i != 1; i = prev[i]){
            f[prev[i]][i] += flow; f[i][prev[i]] -= flow;
        }
        ans += flow;
    }
    
    cout << ans;
    return 0;
}
