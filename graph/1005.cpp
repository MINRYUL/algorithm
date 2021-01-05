//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define MAX 1001
using namespace std;
int t, n, m, x, y, d, cost[MAX], dp[MAX], indegree[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> graph[MAX];
        memset(dp, -1, sizeof(dp)); memset(indegree, 0, sizeof(indegree));
        for(int i = 1; i <= n; i++) cin >> cost[i];
        for(int i = 0; i < m; i++){
            cin >> x >> y; graph[x].push_back(y); indegree[y]++;
        }
        cin >> d; queue<int> q;
        for(int i = 1; i <= n; i++){
            if(!indegree[i]) {
                q.push(i); dp[i] = cost[i];
            }
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int i : graph[node]){
                dp[i] = max(dp[i], dp[node] + cost[i]);
                if(!(--indegree[i])) q.push(i);
            }
        }
        cout << dp[d] << endl;
    }
    return 0;
}
