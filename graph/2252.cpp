//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
vector<int> graph[32001];
int n, m, x, y, temp, indegree[32001];
queue<int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y; graph[x].push_back(y); indegree[y]++;
    }
    for(int i = 1; i <= n; i++) if(!indegree[i]) q.push(i);
    while(!q.empty()){
        temp = q.front(); q.pop();
        cout << temp << ' ';
        for(int i = 0; i < graph[temp].size(); i++){
            indegree[graph[temp][i]]--;
            if(!indegree[graph[temp][i]]) q.push(graph[temp][i]);
        }
    }
    return 0;
}
