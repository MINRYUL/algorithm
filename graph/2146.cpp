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
#define MAX 101
using namespace std;
int n, result = MAX * 2, g[MAX][MAX], num,
    dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> start;
struct Pos{ int x, y; };
bool visited[MAX][MAX];
vector<pair<int, int>> island[10001];

int main(void) {
    cin >> n; queue<pair<Pos, int>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            Pos p = {i, j};
            if(g[i][j]) start.push_back({i, j});
        }
    }
    visited[start[0].first][start[0].second] = true;
    island[0].push_back({start[0].first, start[0].second});
    for(pair<int, int> s : start){
        queue<pair<int, int>> q2; q2.push({s.first, s.second});
        if(!visited[s.first][s.second]){ num++; island[num].push_back({s.first, s.second}); }
        visited[s.first][s.second] = true;
        while(!q2.empty()){
            int tx = q2.front().first, ty = q2.front().second; q2.pop();
            for(int j = 0; j < 4; j++){
                int txx = tx + dx[j], tyy = ty + dy[j];
                if(txx >= 0 && tyy >= 0 && txx < n && tyy < n && g[txx][tyy] && !visited[txx][tyy]){
                    q2.push({txx, tyy}); visited[txx][tyy] = true;
                    island[num].push_back({txx, tyy});
                }
            }
        }
    }
    for(int i = 0; i < num; i++){
        memset(visited, false, sizeof(visited));
        for(pair<int, int> s : island[i]) visited[s.first][s.second] = true;
        
        for(pair<int, int> s : island[i]){
            bool check[MAX][MAX] = {false, };
            Pos p = {s.first, s.second}; q.push({p, 0});
            while(!q.empty()){
                int x = q.front().first.x, y = q.front().first.y, t = q.front().second; q.pop();
                for(int i = 0; i < 4; i++){
                    int xx = x + dx[i], yy = y + dy[i];
                    Pos p2 = {xx, yy};
                    if(xx >= 0 && yy >= 0 && xx < n && yy < n){
                        if(visited[xx][yy]) continue;
                        if(!g[xx][yy] && !check[xx][yy]){
                            q.push({p2, t + 1});
                            check[xx][yy] = true;
                        }else if(t && g[xx][yy]){
                            if(result > t) result = t;
                        }
                    }
                }
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
