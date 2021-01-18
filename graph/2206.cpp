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
#define MAX 1002
using namespace std;
int n, m, graph[MAX][MAX], cost[MAX][MAX][2];
int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};
struct Pos{
    int x, y;
};

int main(void) {
    scanf("%d",&n); scanf("%d",&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
             scanf("%1d", &graph[i][j]);
        }
    }
    Pos p = {0, };
    queue<pair<Pos, int>> q; q.push({p, 0});
    cost[0][0][1] = 1; cost[0][0][0] = 1;
    
    while(!q.empty()){
        Pos p = q.front().first; int t = q.front().second; q.pop();
        for(int i = 0; i < 4; i++){
            int xx = p.x + dx[i], yy = p.y + dy[i];
            Pos temp = {xx, yy};
            if(xx >= 0 && yy >= 0 && xx < n && yy < m){
                if(graph[xx][yy] && t) continue;
                if(!graph[xx][yy] && !cost[xx][yy][t]){
                    cost[xx][yy][t] = cost[p.x][p.y][t] + 1; q.push({temp, t});
                }else if(graph[xx][yy] && !t){
                    if(!cost[xx][yy][1] || cost[xx][yy][1] > cost[p.x][p.y][t] + 1){
                        cost[xx][yy][1] = cost[p.x][p.y][t] + 1; q.push({temp, 1});
                    }
                }
            }
        }
        if(p.x == n - 1 && p.y == m - 1){
            printf("%d \n", cost[p.x][p.y][t]);
            return 0;
        }
    }
    
    printf("-1 \n");
    return 0;
}
