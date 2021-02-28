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
#define MAX 100000
using namespace std;
int n, m, x, y, a, b, r, t, graph[101][101];
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
bool visited[101][101];
vector<pair<int, int>> v[101][101];
vector<pair<int, int>> k;

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }
    
    queue<pair<int, int>> q; q.push({1, 1}); graph[1][1] = 1; visited[1][1] = true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second; q.pop();
        for(pair<int, int> i : v[x][y]){
            if(!graph[i.first][i.second]){
                 t++; graph[i.first][i.second] = 1;
                 for(int j = 0; j < 4; j++){
                     int xx = i.first + dx[j], yy = i.second + dy[j];
                     if(xx > 0 && yy > 0 && xx <= n && yy <= n){
                         if(graph[xx][yy] && visited[xx][yy] && !visited[i.first][i.second]){
                             q.push({i.first, i.second}); visited[i.first][i.second] = true;
                         }
                     }
                 }
            }
        }
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx > 0 && yy > 0 && xx <= n && yy <= n){
                if(graph[xx][yy] && !visited[xx][yy]){
                    q.push({xx, yy}); visited[xx][yy] = true;
                }
            }
        }
    }
    cout << t + 1 << endl;
    return 0;
}
