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
int n, m, result, graph[501][501];
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
bool visited[501][501];

void dfs(int x, int y, int cost, int C){
    if(C == 4 && result < cost){ result = cost; return; }
    else if(C > 4) return;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= m || visited[xx][yy]) continue;
        visited[xx][yy] = true;
        dfs(xx, yy, graph[xx][yy] + cost, C + 1);
        if(C == 1){
            int xxx = xx + dx[i], yyy = yy + dy[i];
            if(!(xxx < 0 || yyy < 0 || xxx >= n || yyy >= m || visited[xxx][yyy])){
                int c = (i + 1) % 2, sum = cost + graph[xx][yy] + graph[xxx][yyy];
                for(int j = 0; j < 4; j++){
                    if(j % 2 == c){
                        xxx = xx + dx[j]; yyy = yy + dy[j];
                        if(xxx < 0 || yyy < 0 || xxx >= n || yyy >= m || visited[xxx][yyy]) continue;
                        if(c && result < (sum + graph[xxx][yyy])) result = sum + graph[xxx][yyy];
                        else if(!c && result < (sum + graph[xxx][yyy])) result = sum + graph[xxx][yyy];
                    }
                }
            }
        }
        visited[xx][yy] = false;
    }
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> graph[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true; dfs(i, j, graph[i][j], 1);
            visited[i][j] = false;
        }
    }
    
    cout << result << endl;
    return 0;
}
