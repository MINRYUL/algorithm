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
#define MAX 202
using namespace std;
int k, w, h, graph[MAX][MAX], cost[MAX][MAX][32];
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1},
    h1[2] = {-1, 1};

struct Pos{
    int x, y;
};

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> k >> w >> h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) cin >> graph[i][j];
    if(w == 1 && h == 1 && !graph[0][0]){ cout << 0 << endl; return 0; }
    
    Pos p = {0, };
    queue<pair<Pos, int>> q; q.push({p, 0});
    for(int i = 0; i < 32; i++) cost[0][0][i] = 1;
    while(!q.empty()){
        int x = q.front().first.x, y = q.front().first.y, t = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            Pos p = {xx, yy};
            if(xx >= 0 && yy >= 0 && xx < h && yy < w){
                if(!cost[xx][yy][t] && !graph[xx][yy]){
                    q.push({p, t}); cost[xx][yy][t] = cost[x][y][t] + 1;
                }
            }
            if(t < k){
                int tx = xx + dx[i], ty = yy + dy[i];
                if(!(i % 2)){
                    for(int z : h1){
                        ty = yy + z;
                        if(tx >= 0 && ty >= 0 && tx < h && ty < w){
                            if(!cost[tx][ty][t + 1] && !graph[tx][ty]){
                                Pos p2 = {tx, ty}; q.push({p2, t + 1});
                                cost[tx][ty][t + 1] = cost[x][y][t] + 1;
                            }
                        }
                    }
                }else{
                    for(int z : h1){
                        tx = xx + z;
                        if(tx >= 0 && ty >= 0 && tx < h && ty < w){
                            if(!cost[tx][ty][t + 1] && !graph[tx][ty]){
                                Pos p2 = {tx, ty}; q.push({p2, t + 1});
                                cost[tx][ty][t + 1] = cost[x][y][t] + 1;
                            }
                        }
                    }
                }
                if(tx == h - 1 && ty == w - 1){
                    cout << cost[tx][ty][t + 1] - 1 << endl; return 0; }
            }
            if(xx == h - 1 && yy == w - 1){
                cout << cost[xx][yy][t] - 1 << endl; return 0; }
        }
    }
   
    cout << -1 << endl;
    return 0;
}
