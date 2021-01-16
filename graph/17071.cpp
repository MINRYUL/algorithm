//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#define MAX 52
using namespace std;
int n, k, graph[2][MAX];
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    if(n == k){
        cout << 0 << endl; return 0;
    }
    
    queue<pair<int, int>> q; q.push({n, 0}); graph[0][n] = 0;
    memset(graph, -1, sizeof(graph));
    while(!q.empty()){
        int x = q.front().first, t = q.front().second; q.pop();
        if((x < 0 || x > 50) || graph[t % 2][x] != -1) continue;
        graph[t % 2][x] = t;
        q.push({x - 1, t + 1}); q.push({x + 1, t + 1}); q.push({2 * x, t + 1});
    }
    
    int tK = k, add = 0, i = 0;
    while(1){
        if(tK + add > 50) break;
        tK += add;
        if(graph[i % 2][tK] != -1 && graph[i % 2][tK] <= i){
            cout << i << endl; return 0;
        }
        add++; i++;
    }

    cout << -1 << endl;
    return 0;
}
