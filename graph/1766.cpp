//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define MAX 32001
using namespace std;
vector<int> graph[MAX];
int n, m, x, y, indegree[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> x >> y, graph[x].push_back(y), indegree[y]++;
    for(int i = 1; i <= n; i++) if(!indegree[i]) pq.push(i);
    while (!pq.empty()) {
        int node = pq.top(); pq.pop(); cout << node << " ";
        for (auto next : graph[node]) if (--indegree[next] == 0) pq.push(next);
    }
    return 0;
}
