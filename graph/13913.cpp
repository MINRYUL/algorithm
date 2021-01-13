//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#define MAX 100002
using namespace std;
int n, k, graph[MAX], dp[MAX], c;
vector<int> result;
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    if(n == k){
        cout << 0 << '\n' << k << endl; return 0;
    }
    queue<int> q; q.push(n); graph[n] = 1; dp[n] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        
        for(int i : {1, -1}){
            if(x + i >= 0 && x + i <= 100000){
                if(!graph[x + i] || ((graph[x] + 1) <= graph[x + i])) dp[x + i] = x;
                
                if((!graph[x + i]) || (graph[x + i] > graph[x] + 1)){
                    q.push(x + i); graph[x + i] = graph[x] + 1;
                }
            }
        }
        if(2 * x <= 100000){
            if(!graph[2 * x] || ((graph[x] + 1) <= graph[2 * x])) dp[2 * x] = x;
            
            if(!graph[2 * x] || (graph[2 * x] > graph[x] + 1)){
                q.push(2 * x); graph[2 * x] = graph[x] + 1;
            }
        }
    }

    cout << graph[k] - 1 << endl;
    c = k; result.push_back(k);
    while(c != n){
        result.push_back(dp[c]); c = dp[c];
    }
    for(int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
    return 0;
}
