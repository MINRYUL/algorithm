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
char graph[6][6];
bool visited[6][6];
int result,
dx[4] = {-1, 0, 1, 0},
dy[4] = {0, -1, 0, 1};
struct Pos{ int x, y; };

void bfs(int x, int y){
    queue<Pos> q; q.push({x, y});
    bool g[6][6];
    int check = 1;
    memcpy(g, visited, sizeof(visited));
    g[x][y] = false;
    while(!q.empty()){
        Pos p = q.front(); q.pop();
        for(int j = 0; j < 4; j++){
            int xx = p.x + dx[j], yy = p.y + dy[j];
            if(xx >= 0 && yy >= 0 && xx < 5 && yy < 5){
                if(g[xx][yy]){
                    g[xx][yy] = false;
                    q.push({xx, yy}); check++;
                }
            }
        }
    }
    if(check == 7) result++;
    return;
}

void dfs(int I, int S, int Y){
    if(S + Y == 7){
        if(Y > S) return;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(visited[i][j]){ bfs(i, j); return; }
    }
    for(int i = I; i < 25; i++){
        int r = i / 5, c = i % 5;
        if(visited[r][c]) continue;
        visited[r][c] = true;
        if(graph[r][c] == 'Y') dfs(i + 1, S, Y + 1);
        else dfs(i + 1, S + 1, Y);
        visited[r][c] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) cin >> graph[i][j];
    dfs(0, 0, 0);
    cout << result << endl;
    return 0;
}
