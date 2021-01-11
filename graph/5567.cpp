//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n, m, x, y, result, depth[501];
vector<int> g[501];
bool visited[501];

void bfs(int start){
    queue<int> q; visited[start] = true;
    for(int i : g[start]){
        q.push(i); depth[i] = 1;
    }
    while(!q.empty()){
        if(!visited[q.front()]){
            if(depth[q.front()] < 3) result++;
            int next = q.front(), add = depth[q.front()] + 1;
            visited[q.front()] = true;
            q.pop();
            for(int i : g[next]){
                if(!visited[i]){
                    q.push(i);
                    if(add < depth[i]) depth[i] = add;
                }
                else continue;
            }
        }else q.pop();
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    for(int i = 0; i <= n; i++) depth[i] = 501;
    
    bfs(1);
    cout << result << endl;
    return 0;
}
