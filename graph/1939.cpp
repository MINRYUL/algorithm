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
#define MAX 10001
#define INF 100001
using namespace std;
int n, m, a, b, c, s, e, mid, l = 0, r;
vector<pair<int, int>> g[MAX];
bool visited[MAX];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c}); g[b].push_back({a, c});
        r = max(c, r);
    }
    cin >> s >> e;
    queue<pair<int, int>> q; q.push({s, INF});
    while(l <= r){
        memset(visited, false, sizeof(visited));
        bool check = false; mid = (l + r)/2;
        queue<int> q; q.push(s); visited[s] = true;
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(x == e){ check = true; break; }
            for(pair<int, int> i : g[x]){
                if(i.second >= mid && !visited[i.first]){
                    visited[i.first] = true; q.push(i.first);
                }
            }
        }
        if(check) l = mid + 1;
        else r = mid - 1;
    }
    
    cout << r << endl;
    return 0;
}
