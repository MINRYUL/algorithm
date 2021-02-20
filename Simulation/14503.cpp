//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int n, m, r, c, d, result, graph[51][51],
dx[4] = {0, -1, 0, 1},
dy[4] = {-1, 0, 1, 0},
dk[4] = {3, 0, 1, 2},
dz[4] = {2, 3, 0, 1},
dX[4] = {-1, 0, 1, 0},
dY[4] = {0, 1, 0, -1};

void dfs(pair<int, int> I, int C){
    if(!graph[I.first][I.second]){ result += 1; graph[I.first][I.second] = 2; }
    for(int i = 0; i < 4; i++){
        int xx = I.first + dx[C], yy = I.second + dy[C];
        if(!graph[xx][yy]){
            dfs({xx, yy}, dk[C]); return;
        }
        C = dk[C];
    }
    int xx = I.first + dX[dz[C]], yy = I.second + dY[dz[C]];
    if(graph[xx][yy] == 1) return;
    else dfs({xx, yy}, C);
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m >> r >> c >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> graph[i][j];
    
    dfs({r, c}, d);
    cout << result << endl;
    return 0;
}
