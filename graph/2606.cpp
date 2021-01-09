//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
vector<int> g[101];
bool visited[101];
int result, n, k, x, y;

void bfs(int start){
    queue<int> q; visited[start] = true;
    for(int i : g[start]) q.push(i);
    while(!q.empty()){
        x = q.front(); q.pop();
        if(!visited[x]) result++;
        visited[x] = true;
        for(int i = 0; i < g[x].size(); i++){
            y = g[x][i];
            if(visited[y]) continue;
            else q.push(y);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    
    bfs(1);
    cout << result << endl;
    return 0;
}
